class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        size_t la = a.size();
        size_t lb = b.size();
        size_t len = la>lb ? la:lb;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (size_t i = 0; i < len; i++) {
            int va = i<la ? a[i]-'0':0;
            int vb = i<lb ? b[i]-'0':0;
            int sum = va+vb+carry;
            ret.insert(ret.begin(), char(sum%2+'0'));
            carry = sum/2;
        }
        if (carry) ret.insert(ret.begin(), char(carry+'0'));
        return ret;
    }
};
