class xor_t
{

    long long identity;

public:
    long long val;
    xor_t()
    {
        identity = 0;
        val = 0;
    }
    long long operation(long long a, long long b)
    {
        return a^b;
    }
    void replace(long long a)
    {
        // val+=a;
        val = a;
    }
};