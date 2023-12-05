QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    util.h

INCLUDEPATH += "/usr/local/include/opencv4/"

LIBS += "/usr/local/lib/libopencv_aruco.so"
LIBS += "/usr/local/lib/libopencv_barcode.so"
LIBS += "/usr/local/lib/libopencv_bgsegm.so"
LIBS += "/usr/local/lib/libopencv_bioinspired.so"
LIBS += "/usr/local/lib/libopencv_calib3d.so"
LIBS += "/usr/local/lib/libopencv_ccalib.so"
LIBS += "/usr/local/lib/libopencv_core.so"
LIBS += "/usr/local/lib/libopencv_datasets.so"
LIBS += "/usr/local/lib/libopencv_dnn.so"
LIBS += "/usr/local/lib/libopencv_dnn_objdetect.so"
LIBS += "/usr/local/lib/libopencv_dnn_superres.so"
LIBS += "/usr/local/lib/libopencv_dpm.so"
LIBS += "/usr/local/lib/libopencv_face.so"
LIBS += "/usr/local/lib/libopencv_features2d.so"
LIBS += "/usr/local/lib/libopencv_flann.so"
LIBS += "/usr/local/lib/libopencv_freetype.so"
LIBS += "/usr/local/lib/libopencv_fuzzy.so"
LIBS += "/usr/local/lib/libopencv_gapi.so"
LIBS += "/usr/local/lib/libopencv_hfs.so"
LIBS += "/usr/local/lib/libopencv_highgui.so"
LIBS += "/usr/local/lib/libopencv_imgcodecs.so"
LIBS += "/usr/local/lib/libopencv_img_hash.so"
LIBS += "/usr/local/lib/libopencv_imgproc.so"
LIBS += "/usr/local/lib/libopencv_intensity_transform.so"
LIBS += "/usr/local/lib/libopencv_line_descriptor.so"
LIBS += "/usr/local/lib/libopencv_mcc.so"
LIBS += "/usr/local/lib/libopencv_ml.so"
LIBS += "/usr/local/lib/libopencv_objdetect.so"
LIBS += "/usr/local/lib/libopencv_optflow.so"
LIBS += "/usr/local/lib/libopencv_phase_unwrapping.so"
LIBS += "/usr/local/lib/libopencv_photo.so"
LIBS += "/usr/local/lib/libopencv_plot.so"
LIBS += "/usr/local/lib/libopencv_quality.so"
LIBS += "/usr/local/lib/libopencv_rapid.so"
LIBS += "/usr/local/lib/libopencv_reg.so"
LIBS += "/usr/local/lib/libopencv_rgbd.so"
LIBS += "/usr/local/lib/libopencv_saliency.so"
LIBS += "/usr/local/lib/libopencv_shape.so"
LIBS += "/usr/local/lib/libopencv_stereo.so"
LIBS += "/usr/local/lib/libopencv_stitching.so"
LIBS += "/usr/local/lib/libopencv_structured_light.so"
LIBS += "/usr/local/lib/libopencv_superres.so"
LIBS += "/usr/local/lib/libopencv_surface_matching.so"
LIBS += "/usr/local/lib/libopencv_text.so"
LIBS += "/usr/local/lib/libopencv_tracking.so"
LIBS += "/usr/local/lib/libopencv_video.so"
LIBS += "/usr/local/lib/libopencv_videoio.so"
LIBS += "/usr/local/lib/libopencv_videostab.so"
LIBS += "/usr/local/lib/libopencv_wechat_qrcode.so"
LIBS += "/usr/local/lib/libopencv_xfeatures2d.so"
LIBS += "/usr/local/lib/libopencv_ximgproc.so"
LIBS += "/usr/local/lib/libopencv_xobjdetect.so"
LIBS += "/usr/local/lib/libopencv_xphoto.so"
