class gcd_t
{
 
    long long identity;

public:
    long long val;
    gcd_t()
    {
        identity = 1;
        val = 1;
    }
    long long operation(long long a, long long b)
    {
        return __gcd(a,b);
    }
    void replace(long long a)
    {
        // val+=a;
        val = a;
    }
};