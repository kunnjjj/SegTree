class max_t
{

    long long identity;

public:
    long long val;
    max_t()
    {
        identity = -1e17;
        val = -1e17;
    }
    long long operation(long long a, long long b)
    {
        return max(a,b);
    }
    void replace(long long a)
    {
        // val+=a;
        val = a;
    }
};