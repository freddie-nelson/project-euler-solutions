#include <stdio.h>
#include <math.h>

unsigned sumOfNaturalMultiples(unsigned multiple, unsigned limit)
{
  unsigned n = floor(limit / multiple); // calculate number of terms between 0 and limit which are multiples of multiple

  // calculate the sum of multiples up to limit
  // using Gauss' sum of an arithmetic series formula
  // we multiply by multiple because the difference between each term is multiple so for every term we want to add the next multiple
  // instead of just the sum of 1, 2, 3...n we will calculate the sum of 1 * multiple, 2 * multiple, 3 * multiple...n * multiple
  return multiple * (n * (n + 1) / 2);
}

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  unsigned limit = 99;
  unsigned m1 = 3;
  unsigned m2 = 5;
  unsigned total = 0;

  // brute force method
  for (size_t i = 0; i <= limit; i++)
  {
    if (i % m1 == 0 || i % m2 == 0)
      total += i;
  }

  printf("brute force: %u ", total);

  // inclusion exclusion method
  total = 0;
  total += sumOfNaturalMultiples(m1, limit);
  total += sumOfNaturalMultiples(m2, limit);

  // subtract where sums collide to account for these collisions being counted twice
  unsigned lcm = m1 * m2 / gcd(m1, m2); // least common multiple is used as this will be where the collisions occur e.g. m1 = 3, m2 = 5, therefore gcd = 1, so lcm = 3 * 5 / 1 = 15
  total -= sumOfNaturalMultiples(lcm, limit);

  printf("\ninclusion exclusion method: %u ", total);

  return 0;
}