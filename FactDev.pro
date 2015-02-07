TEMPLATE = subdirs
CONFIG += ordered c++11
QMAKE_CXXFLAGS += -std=gnu++11

SUBDIRS = \
    src \
    app \
    tests

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
