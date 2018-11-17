#include <assert.h>

#include "picosat.h"

int main() {
  PicoSAT* p = picosat_init();
  picosat_save_original_clauses(p);

  // Add a x.
  picosat_add(p, 1);
  picosat_add(p, 0);

  // Push.
  picosat_push(p);

  // Add a ¬x.
  picosat_add(p, -1);
  picosat_add(p, 0);

  // Check satisfiability of x ∧ ¬x.
  int res = picosat_sat(p, -1);
  assert(res == PICOSAT_UNSATISFIABLE);

  // Pop.
  picosat_pop(p);

  // Check satisfiability of x.
  res = picosat_sat(p, -1);
  assert(res == PICOSAT_SATISFIABLE);

  // Here, we have an assertion failure from picosat:
  //
  //     Assertion failed: (best), function minautarky, file
  //     external/picosat/picosat.c, line 7082.
  picosat_deref_partial(p, 1);

  picosat_reset(p);
}
