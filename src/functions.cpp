#include"header.h"

int initialization(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned int)time(NULL));
    for (int i = 0;i < 13;i++)
        deck[i] = 4; //山札生成
    cout << "コインを何枚購入しますか？";
    int coin;
    cin >> coin;
    return coin;
}

int betting(int coin) {
    int bet;
    while (true) {
        cout << "How many coins would you like to bet?(you have：" << coin << ".)";
        cin >> bet;
        if (bet > coin) {
            cout << "Please enter a number less than the number you have.\n";
            continue;
        }
        return bet;
    }
}

int sum_card(vector<int> a) { //手札の合計を計算する．
    int sum = 0;
    for (int i = 0;i < a.size();i++) {
        if (a[i] > 10) sum += 10; //11~13も10として数えられる
        else sum += a[i];
    }
    if (find(a.begin(), a.end(), 1) != a.end() && sum <= 11)
        sum += 10; //1は1または11の都合の良い方で数えられる
    return sum;
}

int draw() { //カードを引く関数
    int r;
    while (true) {
        r = rand() % 13 + 1; //乱数生成
        if (deck[r - 1] > 0) { //山札に含まれるカードのみ処理
            deck[r - 1]--;
            break;
        }
    }
    return r;
}

void show_card(vector<int> a) {
    cout << "card is"; //カード出力
    for (int i : a)
        cout << i << " ";
    cout << ".\n";
}
