//
// Created by okn-yu on 2022/07/31.
//

#ifndef PRACTICEPATHTRACING_FUTABA_H
#define PRACTICEPATHTRACING_FUTABA_H

#define FTB_VERSION_MAJOR 1
#define FTB_VERSION_MINOR 1
#define FTB_VERSION_PATCH 1

#define FTB_STRINGIFY(x) #x
#define FTB_TOSTRING(x)  FTB_STRINGIFY(x)

/// Current release of Mitsuba
#define FTB_VERSION                                                       \
    FTB_TOSTRING(FTB_VERSION_MAJOR) "."                                   \
    FTB_TOSTRING(FTB_VERSION_MINOR) "."                                   \
    FTB_TOSTRING(FTB_VERSION_PATCH)

/// Year of the current release
#define FTB_YEAR "2022"

/// Authors list
#define FTB_AUTHORS "okn-yu"

#endif //PRACTICEPATHTRACING_FUTABA_H
