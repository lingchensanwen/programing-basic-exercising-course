#include <stdio.h>
#include <stdlib.h>
struct monomial {
int c;
int n;};
struct monomial *construct_monomial(int c, int n) {
  struct monomial *new_monomial = (struct monomial*)malloc(sizeof(struct monomial));
  new_monomial->c = c;
  new_monomial->n = n;
  return new_monomial;
}
void diff_monomial(struct monomial *m) {
  m->c = m->c * m->n;
  m->n = (m->n) - 1;
}
void print_monomial(struct monomial *m) {
  printf("%d*x^%d\n", m->c, m->n);
}
int main() {
struct monomial *m1;
m1 = construct_monomial(-4, 10);
print_monomial(m1); // 表示 -4*x^10
diff_monomial(m1);
print_monomial(m1); // 表示 -40*x^9 return 0;
}
