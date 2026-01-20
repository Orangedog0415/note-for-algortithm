#include <iostream>
#include <vector>
using std::vector;

int gcd(int a, int b){
    return b == 0 ? gcd(b, a % b) : b;
}

long long lcm(int a, int b){
    return (1LL * a / gcd(a, b)) * b;
}

const int N = 100010;
vector<int> prime;
bool is_prime[N];

void Eratosthenes(int n) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) is_prime[i] = true;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime.push_back(i);
      if ((long long)i * i > n) continue;
      for (int j = i * i; j <= n; j += i)
        // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
        // 的倍数开始，提高了运行速度
        is_prime[j] = false;  // 是 i 的倍数的均不是素数
    }
  }
}

int primes[N], cnt = 0;
bool not_prime[N];
void euler(int n){
    not_prime[0] = not_prime[1] = true;

    for(int i = 2; i <= n; i++){
        if(!not_prime[i]){
            primes[cnt++] = i;
        }

        for(int j = 0; j < cnt; j++){
            if(i * primes[i] > n) break;
            not_prime[i * primes[j]] = true;

            // 如果 i 能被 primes[j] 整除，说明 primes[j] 是 i 的最小质因子。
            // 每个数只能被最小质因子筛一次，所以i不能用了。
            if(i % primes[i] == 0) break;
        }
    }
}