class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;
		while (isspace(*s)) s++;
		if (*s=='+' || *s=='-') s++;

		bool eflag = false;
		bool dotflag = false;
		bool before_e = false;
		bool after_e = false;
		bool spaceflag = false;
		while (*s != '\0') {
			if (isdigit(*s)) {
				if (spaceflag) return false;
				if (eflag) after_e = true;
				else before_e = true;
			}
			else if (isspace(*s)) spaceflag = true;
			else if (*s == '.') {
				if (dotflag || eflag || spaceflag) return false;
				else dotflag = true;
			}
			else if (*s=='e' || *s=='E') {
				if (eflag || spaceflag || !before_e) return false;
				else eflag = true;
			} else if (*s=='+' || *s=='-') {
				if (spaceflag) return false;
				if (!eflag || !(*(s-1)=='e' || *(s-1)=='E')) return false;
			} else return false;
			s++;
		}

		if (!before_e) return false;
		else if (eflag && !after_e) return false;
		else return true;
    }
};
