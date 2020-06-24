
int nxt[200000];
void gen_nxt(const string &t)
{
    nxt[0] = 0;
    for (int i = 1; i < t.length(); i++)
    {
        int j = nxt[i - 1];
        while (j && t[i] != t[j])
            j = nxt[j - 1];
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
}