# RungeKutta

The fourth order Runge–Kutta method is a fourth order explicit integration method.

It is one of the most popular, if not the most popular, of all numerical integration methods.

The fourth order Runge–Kutta method for one integration step is as follows. It requires four
function evaluations.

In general, all practical Runge–Kutta methods are required to be consistent.

• Terminology: explicit, semi-explicit, implicit.

1. A Runge-Kutta method is explicit if ajk = 0 for all k ≥ j.
2. A Runge-Kutta method is semi-explicit if ajk = 0 for k > j but there are nonzero
coefficients for some values where k = j.
3. A Runge-Kutta method is implicit if there are coefficients ajk 6= 0 for k > j.
4. There are implicit Runge–Kutta methods of all orders.
5. The value of ajk need not be positive. Negative values are allowed.

• The fourth order RK4 method is the best known and most widely used member of the family.
It is explicit and has four stages.
