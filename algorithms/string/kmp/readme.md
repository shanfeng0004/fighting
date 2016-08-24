原文地址：http://blog.csdn.net/v_july_v/article/details/7041827


KMP的算法流程：
假设现在文本串S匹配到 i 位置，模式串P匹配到 j 位置
如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++，继续匹配下一个字符；
如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]。此举意味着失配时，模式串P相对于文本串S向右移动了j - next[j] 位。”
我们发现如果某个字符匹配成功，模式串首字符的位置保持不动，仅仅是i++、j++；如果匹配失配，i 不变（即 i 不回溯），模式串会跳过匹配过的next[j]个字符。
整个算法最坏的情况是，当模式串首字符位于i - j的位置时才匹配成功，算法结束。
所以，如果文本串的长度为n£??模式串的长度为m，那么匹配过程的时间复杂¶任狾(n)，算上计算next的O(m)时间，KMP的整体时间复杂度为O(m + n)。

扩展1：BM算法

扩展2：Sunday算法


更好理解的一个版本：
http://cache.baiducontent.com/c?m=9f65cb4a8c8507ed4fece763105392230e54f73260878e482a958448e435061e5a37f4bb51734e59949361251cae495cecf53c78200357eddd97d65e98e6d27e20d17876671df65663a30ed8ca5155c437e350&p=8377845bc58a12a05abd9b7e0e15cc&newp=836a840c85cc43ff57ed977d4e568e231610db2151d1d301298ffe0cc4241a1a1a3aecbf26211b04d0c3776c05a94a5ceefb3075370834f1f689df08d2ecce7e&user=baidu&fm=sc&query=kmp%CB%E3%B7%A8&qid=9fe88a1800062161&p1=2
