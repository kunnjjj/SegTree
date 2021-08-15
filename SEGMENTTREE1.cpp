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
  void update(int idx, vector<long long> &A, long long upd, int i, int s, int e)
  {
    if (e < idx)
      return;
    if (s > idx)
      return;
    if (s == e)
    {
      assert(s == idx);
      A[i] = upd;
      tree[i].replace(A[i]);
      return;
    }
    int mid = (s + e) / 2;
    if(idx<=mid)
    update(idx, A, upd, 2 * i + 1, s, mid);
    else
    update(idx, A, upd, 2 * i + 2, mid + 1, e);
    tree[i].val = tree[i].operation(tree[2 * i + 1].val, tree[2 * i + 2].val);
  }
  
  long long query(int qL, int qR, vector<long long> &A, int i, int s, int e)
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
    num_t Lchild = query(qL, qR, A, 2 * i + 1, s, mid);
    num_t Rchild = query(qL, qR, A, 2 * i + 2, mid + 1, e);
    num_t to_return;
    to_return.val = to_return.operation(Lchild.val, Rchild.val);
    // cout << s << " " << e << " " << tree[i].val << endl;
    // cout << "i: " << i << endl;
    return to_return;
  }
};