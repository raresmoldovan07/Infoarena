#include <fstream>
#include <memory>

using namespace std;

class Reader {
  public:
    Reader(const string& filename):
            m_stream(filename),
            m_pos(kBufferSize - 1),
            m_buffer(new char[kBufferSize]) {
        next();
    }

    Reader& operator>>(int& value) {
        value = 0;
        while (current() < '0' || current() > '9')
            next();
        while (current() >= '0' && current() <= '9') {
            value = value * 10 + current() - '0';
            next();
        }
        return *this;
    }

  private:
    const int kBufferSize = (1 << 17);

    char current() {
        return m_buffer[m_pos];
    }

    void next() {
        if (!(++m_pos != kBufferSize)) {
            m_stream.read(m_buffer.get(), kBufferSize);
            m_pos = 0;
        }
    }

    ifstream m_stream;
    int m_pos;
    unique_ptr<char[]> m_buffer;
};

#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
#define NM 250005
using namespace std;

Reader f("pscnv.in");
ofstream g("pscnv.out");

vector < pair < int, int > > graf[NM];
int n, m, x, y, sol[NM], viz[NM];
queue < int > q;

void BellmanFord(int start)
{
    int nod, nod2, c;
    for(int i = 1; i <= n; ++i) sol[i] = inf;
    sol[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        nod = q.front();
        viz[nod] = 0;
        q.pop();
        for(int i = 0; i < graf[nod].size(); ++i)
        {
             nod2 = graf[nod][i].first;
             c = graf[nod][i].second;
             if(max(sol[nod], c) < sol[nod2])
             {
                 sol[nod2] = max(sol[nod], c);
                 if(!viz[nod2])
                 {
                     viz[nod2] = 1;
                     q.push(nod2);
                 }
             }
        }
    }
}

int main()
{
    int a, b, c;
    f >> n >> m >> x >> y;
    for(int i = 1; i <= m; ++i)
    {
        f >> a >> b >> c;
        graf[a].push_back(make_pair(b, c));
    }
    BellmanFord(x);
    g << sol[y] << '\n';
}
