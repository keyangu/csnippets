/**
 * データのダンプ表示
 *
 * 指定されたアドレスからデータをタンプ表示する。
 *
 * @param ptr  表示するバッファ
 * @param len  表示する長さ
 * @return なし
 */
void dumpbuf(unsigned char *ptr, long len)
{
	long i;

	for (i = 0; i < len; i ++) {
		printf("%02x", ptr[i]);
		if (i && ((i % 16) == 15))
			printf("\r\n");
	}

	printf("\r\n");
}

