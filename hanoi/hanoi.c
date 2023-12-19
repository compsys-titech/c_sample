/* 標準(standard)I/O関数(printf, scanfなど)の
   定義が書いてあるファイルを取り込む */
#include <stdio.h>

/* 関数定義
戻り値の型 関数名(引数リスト) {
	関数の中身
}
引数リスト: 「型名 仮引数名(変数名)」を必要個数だけ繰り返す、なければ void
*/
void hanoi(int level, char from, char to, char buf) {
	/* from にある level 枚の板を to に動かす、bufを作業場所として使う */
	
/* 条件分岐
if (条件) {
	条件が真(0以外)のときに実行される部分
} else {
	条件が偽(0)のときに実行される部分
}
*/
	if (level == 1) {
/* printf(format, arg1, arg2, ...);
format の中身を出力する
format内に % で始まる文字があると、argを %直後の型として出力する
	c: char(文字)
	s: char *(文字列、charの配列を \0(文字列終端) に達するまで
	d: int(符号付き整数)
	u: unsigned int(符号なし整数)
	x: unsigned int(ただし16進で表示)
	lf: double(倍精度浮動小数点数)
*/
		printf("Move %c to %c\n", from, to);
	} else {
/* 関数呼び出し
関数名(実引数1, 実引数2, ...);
*/
		hanoi(level - 1, from, buf, to);
		hanoi(1, from, to, buf);
		hanoi(level - 1, buf, to, from);
	}
}

/* プログラム実行時にはmain関数が1回呼ばれる
   引数や戻り値の意味は適宜検索してください */
int main(int argc, char *argv[]) {
/* 変数宣言と初期化
型名 変数名 = 初期値;
(「= 初期値」は省略可能)
*/
	char pins[3] = {'A', 'B', 'C'};
	int level;
	
	printf("Please input the number of plates: ");
	scanf("%d", &level);
	hanoi(level, pins[0], pins[1], pins[2]);
/* 関数の終了
return 戻り値;
戻り値がvoid型の(=戻り値がない)関数の場合、単に return; でよい & 関数末尾であれば省略してもよい
*/
	return 0;
}


