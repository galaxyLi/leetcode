class Solution {
public:
    int atoi(const char *str) {
		long long num = 0;
        if (str != NULL && *str != '\0') {
			bool minus = false;
			while ((*str==' ') && (str!='\0')) str++;
			if (*str == '+') str++;
			else if (*str == '-') {
				minus = true;
				str++;
			}
			if (*str != '\0')
				num = StoI(str, minus);
		}
		return (int)num;
    }
    
	long long StoI(const char *digit, bool minus) {
		long long num = 0;
		while (*digit != '\0') {
			if (('0'<=*digit) && (*digit<='9')) {
				int flag = minus ? -1:1;
				num = 10*num+flag*(*digit-'0');

				if (!minus && num>0x7FFFFFFF) return 0x7FFFFFFF;
				else if(minus && num<(signed int)0x80000000) return 0x80000000;
				digit++;
			} else
				break;
		}
		return num;
	}
};
