#include<iostream>
#include<vector>
using namespace std;

class sum_t
{

    long long identity;

public:
    long long val;
    sum_t()
    {
        identity = 0;
        val = 0;
    }
    sum_t(long long val)
    {
        identity = 0;
        this->val=val;
    }
    long long operation(long long a, long long b)
    {
        return a + b;
    }
    void replace(long long a)
    {
        // val+=a;
        val = a;
    }
};

template <typename num_t>
class seg_tree
{
  vector<num_t> tree;

public:
  int n;
  seg_tree(int N, vector<long long> &A)
  {
    n = N;
    tree = vector<num_t>(4 * N, num_t());
    init(0, n - 1, A, 0);
  }
  void init(int s, int e, vector<long long> &A, int i)
  {
    if (s == e)
    {

      tree[i].val = A[s];
      // cout << s << " " << e << " " << tree[i].val << endl;
      // cout << "i: " << i << endl;
      return;
    }
    int mid = s + (e - s) / 2;
    init(s, mid, A, 2 * i + 1);
    init(mid + 1, e, A, 2 * i + 2);
    tree[i].val = tree[i].operation(tree[2 * i + 1].val, tree[2 * i + 2].val);
    // cout << s << " " << e << " " << tree[i].val << endl;
    // cout << "i: " << i << endl;
  }
  
  void update(int idx,  long long upd, int i, int s, int e)
  {
    if (e < idx)
      return;
    if (s > idx)
      return;
    if (s == e)
    {
      tree[i]=num_t(upd);
      return;
    }
    int mid = (s + e) / 2;
    if(idx<=mid)
    update(idx, upd, 2 * i + 1, s, mid);
    else
    update(idx, upd, 2 * i + 2, mid + 1, e);
    tree[i].val = tree[i].operation(tree[2 * i + 1].val, tree[2 * i + 2].val);
  }
  void update(int idx,int val)
  {
    update(idx,val,0,0,n-1);
  }
  
  num_t query(int qL, int qR, int i, int s, int e)
  {
    if (e < qL)
      return num_t();
    if (s > qR)
      return num_t();
    if (qL <= s && e <= qR)
    {

      // cout << s << " " << e << " " << tree[i].val << endl;
      // cout << "i: " << i << endl;
      return tree[i];
    }
    int mid = s + (e - s) / 2;
    num_t Lchild = query(qL, qR,  2 * i + 1, s, mid);
    num_t Rchild = query(qL, qR,  2 * i + 2, mid + 1, e);
    num_t to_return;
    to_return.val = to_return.operation(Lchild.val, Rchild.val);
    // cout << s << " " << e << " " << tree[i].val << endl;
    // cout << "i: " << i << endl;
    return to_return;
  }
  num_t query(int qL,int qR)
  {
    return query(qL,qR,0,0,n-1);
  }
};

int main()
{

    int n;
	cin >> n;
	int q;
	cin >> q;
    vector<long long> A(n);
    for(int i=0;i<n;i++)
    {
      cin>>A[i];
    }
    seg_tree<sum_t> T=seg_tree<sum_t> (n,A);

    for (int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		
		if (type == 1)
		{
			int x; long long y; cin>>x>>y;
			x--;
			T.update(x,y);
		}
		else
		{
			int x,y; cin>>x>>y;
			x--;y--;
			cout<<T.query(x,y).val<<endl;
		}
	}
 
	return 0;
}