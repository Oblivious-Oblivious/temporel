#ifndef __TEMPOREL_PROFILER_MODULE_SPEC_H_
#define __TEMPOREL_PROFILER_MODULE_SPEC_H_

#include "../../libs/cSpec/export/cSpec.h"

#include <unistd.h>

#define TEMPOREL_ENABLE_PROFILER
#include "../../src/profiler/profiler.h"

#include <unistd.h>

#ifndef usleep
extern int usleep(unsigned int __useconds);
#endif

module(T_profiler, {
  it("tests random profiles", {
    int i;
    TEMPOREL_PROFILE({ usleep(10000); });
    for(i = 0; i < 10; ++i) {
      TEMPOREL_PROFILE("foo for", {
        usleep(10000);
        usleep(10000);
        usleep(10000);
        usleep(10000);
      });
    }

    temporel_profiler_display();
  });
})

#endif
