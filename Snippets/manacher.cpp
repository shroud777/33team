//build tempS->s
        s = "^";
        s += "#";
        for (int i = 0; i < tempS.length(); i++)
            s += tempS[i], s += "#";
        s += "$";
        int n = s.length();
        //manacher
        int C, R;
        C = R = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int i_mirror = 2 * C - i; //C - i_mirror = i - C
            if (R > i)
                P[i] = min(R - i, P[i_mirror]);
            else
                P[i] = 0;
            while (s[i + P[i] + 1] == s[i - P[i] - 1])
            {
                P[i]++;
            }
            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }