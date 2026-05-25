#include "../libs/cSpec/export/cSpec.h"
#include "profiler/profiler.module.spec.h"

int main(void) {
  cspec_run_suite("all", { T_profiler(); });
}
