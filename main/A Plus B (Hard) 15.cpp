#include <bits/stdc++.h>
using namespace std;
struct bigint {
    static const int BASE = 1000000000, BASE_DIGITS = 9;
    static const long long BASE2 = 1000000000000000000;
    std::vector<int> a;
    //If sign == 1,number is negative. If sign == 0, number is non-negative
    int sign = 0;
    bigint() {}
    bigint(long long num) {
        a.clear();
        sign = (num < 0);
        if(sign) num = -num;
        while(num != 0) {
            a.push_back(num%BASE);
            num /= BASE;
        }
    }
    bigint(const int num) {*this = bigint((long long)num);}
    bigint(const std::string &num) {scan(num);}
    bigint(const char *num) {scan(std::string(num));}
    void scan(const std::string &s) {
        a.clear();
        sign = (s[0] == '-');
        if(s.length() == 1+sign && s[sign] == '0') {sign = 0; return;}
        for(int i = s.length()-1; i >= sign; i -= BASE_DIGITS) {
            int curr = 0;
            for(int j = std::max(i-BASE_DIGITS+1,sign); j <= i; j++) curr = curr*10+(s[j]^48);
            a.push_back(curr);
        }
        trim();
    }
    bool isZero() const {return a.empty();}
    int compareabs(const bigint &bi) const {
        //return 1 if *this is greater, 0 if bi is greater, -1 if they are equal
        if(a.size() != bi.a.size()) return (a.size() > bi.a.size());
        for(int i = a.size()-1; i >= 0; i--) {
            if(a[i] != bi.a[i]) return (a[i] > bi.a[i]);
        }
        return -1;
    }
    void trim() {
        while(!a.empty() && a.back() == 0) a.pop_back();
        if(a.empty()) sign = 0;
    }
    void flipSign() {sign = !sign;}
    void toAbs() {sign = 0;}
    void operator = (const bigint &bi) {
        sign = bi.sign;
        a = bi.a;
    }
    bool operator > (const bigint &bi) const {
        if(sign != bi.sign) return bi.sign;
        return (compareabs(bi) == !sign);
    }
    bool operator < (const bigint &bi) const {
        if(sign != bi.sign) return sign;
        return (compareabs(bi) == sign);
    }
    bool operator >= (const bigint &bi) const {return !(*this < bi);}
    bool operator <= (const bigint &bi) const {return !(*this > bi);}
    bool operator == (const bigint &bi) const {
        if(sign != bi.sign || a.size() != bi.a.size()) return 0;
        return (compareabs(bi) == -1);
    }
    bool operator != (const bigint &bi) const {return !(*this == bi);}
    bigint operator - () const {
        bigint ans = *this;
        ans.sign = !ans.sign;
        return ans;
    }
    bigint operator + (bigint &bi) {
        if(sign == bi.sign) {
            bigint ans = ((a.size() > bi.a.size())?*this:bi);
            const bigint *ptr = (a.size() > bi.a.size()?&bi:this);
            ans.sign = sign;
            int carry = 0;
            for(int i = 0; i < ptr->a.size(); i++) {
                ans.a[i] += ptr->a[i]+carry;
                if(ans.a[i] >= BASE) {
                    ans.a[i] -= BASE;
                    carry = 1;
                } else carry = 0;
            }
            if(carry) {
                ans.a.push_back(0);
                for(int i = ptr->a.size();; i++) {
                    ans.a[i]++;
                    if(ans.a[i] == BASE) ans.a[i] = 0;
                    else break;
                }
                ans.trim();
            }
            return ans;
        } else {
            bi.flipSign();
            return *this-bi;
            bi.flipSign();
        }
    }
    bigint operator - (bigint &bi) {
        if(sign == bi.sign) {
            bool ord = (compareabs(bi) != 0);
            bigint ans = (ord?*this:bi);
            const bigint *ptr = (ord?&bi:this);
            ans.sign = (ord?sign:!sign);
            int carry = 0;
            for(int i = 0; i < ptr->a.size(); i++) {
                ans.a[i] -= ptr->a[i]+carry;
                if(ans.a[i] < 0) {
                    ans.a[i] += BASE;
                    carry = 1;
                } else carry = 0;
            }
            if(carry) {
                for(int i = ptr->a.size();; i++) {
                    ans.a[i]--;
                    if(ans.a[i] < 0) ans.a[i] += BASE;
                    else break;
                }
            }
            ans.trim();
            return ans;
        } else {
            bi.flipSign();
            return *this+bi;
            bi.flipSign();
        }
    }
    void operator += (bigint &bi) {
        if(sign == bi.sign) {
            a.resize(std::max(a.size(),bi.a.size()),0);
            int carry = 0;
            for(int i = 0; i < bi.a.size(); i++) {
                a[i] += bi.a[i]+carry;
                if(a[i] >= BASE) {
                    a[i] -= BASE;
                    carry = 1;
                } else carry = 0;
            }
            if(carry) {
                a.push_back(0);
                for(int i = bi.a.size();; i++) {
                    a[i]++;
                    if(a[i] == BASE) a[i] = 0;
                    else break;
                }
                trim();
            }
        } else {
            bi.flipSign();
            *this -= bi;
            bi.flipSign();
        }
    }
    void operator -= (bigint &bi) {
        if(sign == bi.sign) {
            if(compareabs(bi) != 0) {
                int carry = 0;
                for(int i = 0; i < bi.a.size(); i++) {
                    a[i] -= bi.a[i]+carry;
                    if(a[i] < 0) {
                        a[i] += BASE;
                        carry = 1;
                    } else carry = 0;
                }
                if(carry) {
                    for(int i = bi.a.size();; i++) {
                        a[i]--;
                        if(a[i] < 0) a[i] += BASE;
                        else break;
                    }
                }
                trim();
            } else {
                sign = !sign;
                a.resize(bi.a.size(),0);
                for(int i = 0; i < a.size(); i++) {
                    a[i] = bi.a[i]-a[i];
                    if(a[i] < 0) {
                        a[i] += BASE;
                        a[i+1]++;
                    }
                }
            }
            trim();
        } else {
            bi.flipSign();
            *this += bi;
            bi.flipSign();
        }
    }
    bigint simpleMultiplication(const bigint &bi) const {
        bigint ans;
        if(isZero() || bi.isZero()) return ans;
        ans.sign = sign^bi.sign;
        if(a.size() == 1 && a[0] == 1) return bi;
        if(bi.a.size() == 1 && bi.a[0] == 1) return *this;
        ans.a.resize(a.size()+bi.a.size(),0);
        long long curr = 0, carry = 0;
        for(int p = 0; p < a.size()+bi.a.size(); p++) {
            if(carry >= BASE) {
                curr = carry%BASE;
                carry /= BASE;
            } else {
                curr = carry;
                carry = 0;
            }
            for(int i = std::min(p,(int)a.size()-1),j = p-i; i >= 0 && j < bi.a.size(); i--,j++) {
                curr += (long long)a[i]*bi.a[j];
                if(curr >= BASE2) {
                    curr -= BASE2;
                    carry += BASE;
                }
            }
            ans.a[p] = (int)(curr%BASE);
            carry += curr/BASE;
        }
        ans.trim();
        return ans;
    }
    bigint operator * (const bigint &bi) const {
        return simpleMultiplication(bi);
    }
    void operator *= (const bigint &bi) {*this = *this*bi;}
    friend std::istream& operator >> (std::istream &in, bigint &bi) {
        std::string str; in >> str;
        bi.scan(str);
        return in;
    }
    friend std::ostream& operator << (std::ostream &out, const bigint &bi) {
        if(bi.sign) out << "-";
        if(bi.isZero()) out << 0;
        else out << bi.a.back();
        for(int i = bi.a.size()-2; i >= 0; i--) out << std::setw(BASE_DIGITS) << std::setfill('0') << bi.a[i];
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    bigint a,b;
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a >> b;
        cout << a+b << endl;
    }
    return 0;
}