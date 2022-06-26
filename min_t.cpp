class min_t
{ 

    long long identity;

public:
    long long val;
    min_t()
    {
        identity = +1e17;
        val = +1e17;
    }
    long long operation(long long a, long long b)
    {
        return min(a,b);
    }
    void replace(long long a)
    {
        // val+=a;
        val = a;
    }
};