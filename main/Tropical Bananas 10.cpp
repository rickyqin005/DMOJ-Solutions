#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <unistd.h>

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct Scanner {
  int fd = -1;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += ::read(fd, line + ed, (1 << 15) - ed);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) {
      ref = 10 * ref + (line[st++] & 0xf);
    }
    if (neg) ref = -ref;
    return true;
  }
  template <class T> bool read_single(V<T>& ref) {
    for (auto& d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T> bool read_single(array<T,2>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    return true;
  }
  template <class T> bool read_single(array<T,3>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    if (!read_single(ref[2])) return false;
    return true;
  }
  template <class T> bool read_single(array<T,4>& ref) {
    if (!read_single(ref[0])) return false;
    if (!read_single(ref[1])) return false;
    if (!read_single(ref[2])) return false;
    if (!read_single(ref[3])) return false;
    return true;
  }
  void read() {}
  template <class H, class... T> void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
public:
  template <bool F = false> void write() {}
  template <bool F = false, class H, class... T>
  void write(const H& h, const T&... t) {
    if (F) write_single(' ');
    write_single(h);
    write<true>(t...);
  }
  template <class... T> void writeln(const T&... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE* _fp) : fp(_fp) {}
  ~Printer() { flush(); }

private:
  static constexpr size_t SIZE = 1 << 15;
  FILE* fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write_single(const char& val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write_single(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write_single('0');
      return;
    }
    if (val < 0) {
      write_single('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) {
      line[pos + i] = small[len - 1 - i];
    }
    pos += len;
  }
  void write_single(const string& s) {
    for (char c : s) write_single(c);
  }
  void write_single(const char* s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T> void write_single(const V<T>& val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};
Printer out(stdout);
Scanner input(stdin);
ll diff[200002];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(diff, 0, sizeof(diff));
    int N,Q; input.read(N,Q);
    int x,l,r; ll a,b;
    for(int i = 1; i <= Q; i++) {
        input.read(x, l, r, a, b);
        if(x == 0) {
            diff[l] += a+b;
            diff[l+1] += -a;
            diff[r+1] += -(a+b*(r-l+1))-b;
            diff[r+2] += a+b*(r-l+1);
        } else {
            diff[l] += a+b*(r-l+1);
            diff[l+1] += -(a+b*(r-l+1))-b;
            diff[r+1] += -a;
            diff[r+2] += a+b;
        }
    }
    for(int i = 1; i <= N; i++) diff[i] += diff[i-1];
    for(int i = 1; i <= N; i++) diff[i] += diff[i-1];
    for(int i = 1; i <= N; i++) out.writeln(diff[i]);
    return 0;
}