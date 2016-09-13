// a的b次方对c取模
__int64 FastM(__int64 a, __int64 b, __int64 c) {
  if (b == 0) return 1;
  __int64 t, sum;
  t = a % c;
  sum = 1;
  while (b) {
    if (b & 1) sum = (sum * t) % c;
    t = (t * t) % c;
    b >>= 1;
  }
  return sum;
}
