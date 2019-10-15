long fact(long n) {
  return (n==0||n==1) ? 1 : (fact(n-1) * n);
}