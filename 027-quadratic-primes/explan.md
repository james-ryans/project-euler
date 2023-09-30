# Quadratic Primes

Considering quadratics of the form:

$n^2 + an + b$, where $|a| < 1000$ and $|b| < 1000$

Find the product of the coefficients, $a$ and $b$,
for the quadratic expression that produces the maximum
number of primes for consecutive values of $n$,
starting with $n = 0$.

## Preparation

From this source https://t5k.org/notes/GapsTable.html,
we can get the greatest prime gap under a certain number.

## Idea

My assumption is $n$ will be pretty much below $80$.
By ignoring $b$ because it is a constant that don't affect
the prime gap, $a = -1000$ and $n = 80$, the equation
grows much faster than the prime number can follow.

As we can see at $31397$ the prime gap is at most $71$ while
the gap between two quadratic $n_1 = 80$ and $n_2 = 81$ is $81$
and the resulting number $80^2 + 80 + 1000 = 7480$ which is
less than $31397$. If we increase the $a$, the gap will go
even further so my initial assumption is valid.

Looping $-1000 < a < 1000$, $-1000 \le b \le 1000$, and
$0 < n < 80$ will have $O(3.2*10^8)$ time complexity.

Without increasing the time complexity above,
we can predefine prime numbers for $0 < n < 10000$ with Sieve of
Eratosthenes for checking if the number is prime in $O(1)$.
