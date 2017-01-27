#-------------------------------------------------
#
# Project created by QtCreator 2016-12-31T12:09:16
#
#-------------------------------------------------

QT       += testlib
QT       += widgets

QT       -= gui

TARGET = tst_testsoftwaresimulationtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testsoftwaresimulationtest.cpp \
        user.cpp \
        student.cpp \
        researcher.cpp \
        it_support.cpp \
        request.cpp \
        job.cpp \
        curriculum.cpp \
        departmentstructure.cpp \
        scheduler.cpp \
        machine.cpp \
        setoffunctions.cpp \
        dividezero.cpp \
        unknowtypejob.cpp \
        docopen.cpp \
        badinput.cpp \


HEADERS  += user.h \
        student.h \
        researcher.h \
        request.h \
        job.h \
        curriculum.h \
        departmentstructure.h \
        scheduler.h \
        it_support.h \
        machine.h \
        setoffunctions.h \
        dividezero.h \
        unknowtypejob.h \
        docopen.h \
        badinput.h \


DEFINES += SRCDIR=\\\"$$PWD/\\\"
