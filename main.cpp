#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <fstream>
#include <opencv2/dnn/all_layers.hpp>
#include <util.h>

using namespace std;
using namespace cv;
using namespace dnn;

int main(){

    //baca path
    string file_path = "/home/user/DeteksiDNN/custom/coupler/";

    //inisialisasi string kedalam vektor
    vector<string> class_names;

    //load file label
    ifstream ifs(string(file_path + "voc.txt").c_str());

    //inisialisasi string untuk label
    string line;

    //loop untuk memasukan label ke vektor class_names
    while (getline(ifs, line))
    {
        //untuk menampilkan output line dari class name yang terdeteksi
        cout << line << endl;

        //memasukan output string line kedalam vektor
        class_names.push_back(line);
    }

    //Memberi warna untuk setiap class name dari label (di setting di class header)
    vector<Scalar> colors = getClassColors( class_names.size() );

    //Membaca model dan config OpenCV DNN
    auto net = readNet(file_path + "frozen_inference_graph.pb",file_path + "graph.pbtxt","Tensorflow");

    //Fungi OpenCV Buka Camera
    VideoCapture cap(0);

    //Menjalankan di CPU atau GPU
    net.setPreferableBackend(DNN_BACKEND_OPENCV); //CPU
    net.setPreferableTarget(DNN_TARGET_CPU);

    //net.setPreferableBackend(DNN_BACKEND_CUDA); //GPU
    //net.setPreferableTarget(DNN_TARGET_CUDA);


    //Set parameter minimal confidence
    float min_confidence_score = 0.5;


    //Looping program ketika membuka kamera
    while (cap.isOpened()){
        //Buat frame
        Mat frame;

        //membuat syarat dari status kamera
        bool isSuccess = cap.read(frame);

        //Memastikan frame bisa di load
        if (!isSuccess){
            cout << "Could not load the frame!" << endl;
            break;
        }

        //Timer resolusi awal baca blob (untuk baca fps)
        auto start = getTickCount();

        //Membuat matrix blob dari frame
        Mat blob = blobFromImage(frame, 1.f, Size(600, 600), Scalar(0, 0, 0), true, false); //cari tahu size

        //Set blob menjadi inputan DNN
        net.setInput(blob);

        //Menyimpan blob dari DNN untuk mendapatkan prediksi
        Mat output = net.forward();

        //Matrix dari semua hasil deteksi
        Mat results(output.size[2], output.size[3], CV_32F, output.ptr<float>());

        //Timer resolusi akhir baca blob (untuk baca fps)
        auto end = getTickCount();

        //Loop baca prediksi
        for (int i =0; i <results.rows; i++){
            int class_id = int(results.at<float>(i,1));
            float confidence = results.at<float>(i, 2);

            // Cek deteksi jika sudah memenuhi minimal confidence lalu membuat kotak deteksi
            if (confidence > min_confidence_score){

                //keempat line dibawah untuk menentukan start point dan end point dari objek yang terdeteksi
                const int32_t bboxX      = static_cast<int32_t>( results.at<float>( 3 ) * frame.cols );
                const int32_t bboxY      = static_cast<int32_t>( results.at<float>( 4 ) * frame.rows );
                const int32_t bboxWidth  = static_cast<int32_t>( results.at<float>( 5 ) * frame.cols ) - bboxX;
                const int32_t bboxHeight = static_cast<int32_t>( results.at<float>( 6 ) * frame.rows ) - bboxY;

                //fungsi untuk menentukan titik koordinat deteksi
                Rect rectangle = Rect( bboxX, bboxY, bboxWidth, bboxHeight );

                //menentukan warna dari kotak deteksi berdasarkan file label (di setting di class header)
                Scalar color = colors[class_id];

                //menentukan ketebalan garis kotak deteksi
                constexpr int32_t thickness = 3;

                //fungsi membuat kotak deteksi openCV
                cv::rectangle( frame, rectangle, color, thickness );

                //menentukan nama dari kotak deteksi berdasarkan file label (di setting di class header)
                string class_name = class_names[class_id-1];

                //fungsi menambahkan text dari file label ke frame (untuk penamaan deteksi)
                putText(frame, class_name + " " + to_string(int(confidence*100)) + "%", Point(bboxX, bboxY - 5), FONT_HERSHEY_SIMPLEX, 0.6, color, 1);
            }
        }

        //rumus fps
        auto totalTime = (end - start) / getTickFrequency();
        cout << "time : " << totalTime << endl;

        //fungsi menambahkan text untuk hasil fps
        putText(frame, "FPS: " + to_string(int(1 / totalTime)), Point(10,20), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 255, 0),false);

        //menampilkan hasil frame
        imshow("deteksi coupler", frame);

        //menunggu buka kamera
        int k = waitKey(10);

        //syarat looping "while" berhenti
        if (k == 113){
            break;
        }
    }

    //menutup kamera setelah program "while" berhenti
    cap.release();

    //menutup semua program yang berjalan
    destroyAllWindows();
}
