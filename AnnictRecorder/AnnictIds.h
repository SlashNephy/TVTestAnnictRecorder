
#pragma once

#include "pch.h"

namespace Annict
{
    static std::optional<uint16_t> SyoboCalTidToAnnictId(const uint16_t tid)
    {
        switch (tid)
        {
        // 2010年春
        case 1893:  // GIANT KILLING
            return 857;
        case 1866:  // MAJOR 第6シリーズ
            return 2196;
        case 2409:  // プリキュアオールスターズDX2 希望の光☆レインボージュエルを守れ！
            return 3631;
        case 1894:  // 閃光のナイトレイド
            return 1145;
        case 1905:  // ジュエルペット てぃんくる
            return 908;
        case 1887:  // さらい屋 五葉
            return 810;
        case 2063:  // ゆとりちゃん
            return 3827;
        case 1906:  // 裏切りは僕の名前を知っている
            return 239;
        case 1928:  // まじっく快斗
            return 2027;
        case 1912:  // トランスフォーマー アニメイテッド
            return 1443;
        case 1904:  // kiss×sis
            return 487;
        case 1888:  // いちばんうしろの大魔王
            return 134;
        case 1898:  // 荒川アンダー ザ ブリッジ
            return 108;
        case 1892:  // おおきく振りかぶって～夏の大会編～
            return 290;
        case 1896:  // Angel Beats!
            return 244;
        case 1885:  // WORKING!!
            return 2459;
        case 3498:  // イヴの時間 劇場版
            return 3146;
        case 1882:  // けいおん！！
            return 669;
        case 1920:  // SDガンダム三国伝 Brave Battle Warriors
            return 259;
        case 2131:  // リングにかけろ1 影道編
            return 2367;
        case 2672:  // 名探偵コナン 天空の難破船
            return 3726;
        case 1890:  // 会長はメイド様！
            return 429;
        case 1867:  // 四畳半神話大系
            return 2321;
        case 2186:  // 劇場版 銀魂 新訳紅桜篇
            return 3232;
        case 1883:  // 真・恋姫†無双～乙女大乱～
            return 981;
        case 1916:  // 最強武将伝 三国演義
            return 7734;
        case 2201:  // 劇場版 "文学少女"
            return 3635;
        case 2184:  // 東のエデン 劇場版Ⅱ Paradise Lost
            return 3615;
        case 2017:  // 劇場版 ブレイク ブレイド 第一章「覚醒ノ刻」
            return 3627;
        case 1897:  // 薄桜鬼
            return 1735;
        case 1886:  // B型H系
            return 1751;
        case 1908:  // HEROMAN
            return 1752;
        case 1910:  // ひめチェン！おとぎちっくアイドル リルぷりっ
            return 1773;
        case 1889:  // 迷い猫オーバーラン！
            return 2087;
        case 1913:  // メタルファイトベイブレード 爆
            return 5029;
        case 1903:  // はなかっぱ
            return 1614;

        // 2010年夏
        case 2901:  // 劇場版 機動戦士ガンダム00 -A wakening of the Trailblazer-
            return 3229;
        case 2187:  // ブラック★ロックシューター（OVA）
            return 2989;
        case 2024:  // ポケットモンスター ベストウイッシュ
            return 1987;
        case 2282:  // ToHeart2 adnext
            return 2873;
        case 2343:  // こわれかけのオルゴール
            return 3302;
        case 1977:  // 屍鬼
            return 943;
        case 1976:  // ストライクウィッチーズ2
            return 1031;
        case 1953:  // 生徒会役員共
            return 1127;
        case 1993:  // クイーンズブレイド 美しき闘士たち
            return 2674;
        case 1957:  // アマガミSS
            return 76;
        case 1971:  // 祝福のカンパネラ
            return 984;
        case 1963:  // 宇宙ショーへようこそ
            return 3167;
        case 1970:  // みつどもえ
            return 2136;
        case 1956:  // オオカミさんと七人の仲間たち
            return 330;
        case 1981:  // デジモンクロスウォーズ
            return 1354;
        case 1964:  // BLACK LAGOON Roberta's Blood Trail
            return 2968;
        case 1959:  // 伝説の勇者の伝説
            return 1368;
        case 1968:  // 学園黙示録 HIGHSCHOOL OF THE DEAD
            return 435;
        case 1972:  // 黒執事Ⅱ
            return 658;
        case 5729:  // 借りぐらしのアリエッティ
            return 3203;
        case 1967:  // あそびにいくヨ！
            return 37;
        case 1958:  // セキレイ～Pure Engagement～
            return 1083;
        case 1966:  // 世紀末オカルト学院
            return 1098;
        case 1969:  // 戦国BASARA弐
            return 1106;
        case 2690:  // 劇場版 NARUTO -ナルト- 疾風伝 ザ・ロストタワー
            return 3556;
        case 1965:  // ぬらりひょんの孫
            return 1546;
        case 2015:  // バトルスピリッツ ブレイヴ
            return 1661;
        case 1984:  // 殿といっしょ 1分間劇場
            return 1484;
        case 1987:  // モンハン日記 ぎりぎりアイルー村 ☆アイルー危機一髪☆
            return 2239;

        // 2010年秋
        case 2037:  // バクマン。
            return 1650;
        case 2061:  // リタとナントカ
            return 2361;
        case 3195:  // カルルとふしぎな塔
            return 397;
        case 2023:  // 探偵オペラ ミルキィホームズ
            return 1237;
        case 2028:  // ヨスガノソラ
            return 2316;
        case 2097:  // とある科学の超電磁砲 OVA
            return 2870;
        case 2044:  // STAR DRIVER 輝きのタクト
            return 1005;
        case 3255:  // 夜桜四重奏～ホシノウミ～
            return 3092;
        case 2019:  // 荒川アンダー ザ ブリッジ×ブリッジ
            return 107;
        case 2051:  // 海月姫
            return 649;
        case 2400:  // 劇場版イナズマイレブン 最強軍団オーガ襲来
            return 3149;
        case 2003:  // たまゆら
            return 2815;
        case 2030:  // そらのおとしものf
            return 1159;
        case 2040:  // 神のみぞ知るセカイ
            return 460;
        case 2042:  // 侵略！イカ娘
            return 918;
        case 2029:  // とある魔術の禁書目録Ⅱ
            return 1423;
        case 2053:  // 宮西達哉劇場 おまえうまそうだな
            return 344;
        case 2034:  // 俺の妹がこんなに可愛いわけがない
            return 338;
        case 2058:  // ロビンくんと100人のお友達
            return 2444;
        case 2526:  // カッコカワイイ宣言！
            return 393;
        case 2035:  // スーパーロボット大戦OG -ジ・インスペクター-
            return 1055;
        case 2070:  // 這いよる！ニャルアニ リメンバー・マイ・ラブ(クラフト先生)
            return 1739;
        case 2047:  // アイアンマン (2010)
            return 50;
        case 2041:  // パンティ＆ストッキングwithガーターベルト
            return 1688;
        case 2018:  // それでも町は廻っている
            return 1162;
        case 2027:  // 心霊探偵 八雲
            return 946;
        case 2056:  // 眼鏡なカノジョ
            return 3074;
        case 2603:  // REDLINE
            return 3771;
        case 2036:  // テガミバチ REVERSE
            return 1345;
        case 3300:  // 蒼穹のファフナー HEAVEN AND EARTH
            return 3430;
        case 2032:  // 咎狗の血
            return 1475;
        case 2095:  // Starry☆Sky
            return 3807;
        case 2021:  // おとめ妖怪 ざくろ
            return 301;
        case 2278:  // ハートキャッチプリキュア！花の都でファッションショー…ですか！？
            return 3583;
        case 3237:  // マルドゥック・スクランブル
            return 3693;
        case 2031:  // 薄桜鬼 碧血録
            return 1736;
        case 2039:  // えむえむっ！
            return 262;
        case 2022:  // 百花繚乱 サムライガールズ
            return 1813;
        case 2033:  // もっと To LOVEる
            return 2222;
        case 2192:  // ユメミル、アニメ onちゃん シーズン2
            return 2280;
        case 2050:  // 夢色パティシエールSP プロフェッショナル
            return 2299;
        case 2043:  // FORTUNE ARTERIAL 赤い約束
            return 1859;
        case 1536:  // 劇場版 空の境界 終章/空の境界
            return 6127;

        // 2010年冬
        case 1998:  // テイルズ オブ シンフォニア THE ANIMATION テセアラ編
            return 2845;
        case 1795:  // バカとテストと召喚獣
            return 1648;
        case 2789:  // ルパン三世 the Last Job
            return 2383;
        case 1666:  // COBRA THE ANIMATION
            return 709;
        case 1827:  // 刀語
            return 430;
        case 1853:  // ハートキャッチプリキュア！
            return 1646;
        case 1907:  // マリー&ガリー Ver.2.0
            return 6739;
        case 2661:  // プリンセスと魔法のキス
            return 8075;
        case 1900:  // 書家
            return 962;
        case 1802:  // デュラララ!!
            return 1363;
        case 1828:  // 聖痕のクェイサー
            return 1139;
        case 1826:  // のだめカンタービレ フィナーレ
            return 1563;
        case 4581:  // 魔法少女リリカルなのは The MOVIE 1st
            return 3702;
        case 5684:  // DARKER THAN BLACK -黒の契約者- 外伝
            return 5912;
        case 1820:  // ダンス イン ザ ヴァンパイアバンド
            return 1222;
        case 2185:  // 涼宮ハルヒの消失
            return 3371;
        case 1787:  // はなまる幼稚園
            return 1615;
        case 2313:  // 装甲騎兵ボトムズ 幻影篇
            return 2813;
        case 1796:  // れでぃ×ばと！ Ladies versus Butlers！
            return 2415;
        case 1938:  // 怪盗レーニャ
            return 450;
        case 1809:  // ひだまりスケッチ×☆☆☆
            return 1764;
        case 2130:  // 機動戦士ガンダムUC（ユニコーン）
            return 2653;
        case 1797:  // ソ・ラ・ノ・ヲ・ト
            return 1165;
        case 3343:  // 劇場版 遊☆戯☆王 ～超融合！時空を越えた絆～
            return 3750;
        case 1810:  // ちゅーぶら！！
            return 1264;
        case 2248:  // 劇場版 Fate/stay night - UNLIMITED BLADE WORKS
            return 3638;
        case 1872:  // 一騎当千 XTREME XECUTOR
            return 159;
        case 1819:  // おおかみかくし
            return 288;
        case 1891:  // 爆丸バトルブローラーズ ニューヴェストロイア
            return 1708;
        case 1299:  // 遙かなる時空の中で3 終わりなき運命
            return 1743;
        case 1823:  // おまもりひまり
            return 311;
        case 1839:  // 増田こうすけ劇場 ギャグマンガ日和＋
            return 2077;

        // 2011年春
        case 2121:  // 聖痕のクェイサーII
            return 1140;
        case 2823:  // 鬼神伝
            return 3195;
        case 2623:  // 劇場版 戦国BASARA -The Last Party-
            return 3376;
        case 2119:  // Dororonえん魔くん メ～ラめら
            return 1406;
        case 2143:  // そふてにっ
            return 1157;
        case 2163:  // リングにかけろ１ 世界大会編
            return 2368;
        case 2138:  // 戦国乙女～桃色パラドックス～
            return 1109;
        case 2148:  // TIGER & BUNNY
            return 1192;
        case 2146:  // DOG DAYS
            return 1404;
        case 2176:  // とっとこハム太郎でちゅ
            return 1428;
        case 2092:  // テレビまんが 昭和物語
            return 959;
        case 2867:  // 豆富小僧
            return 3548;
        case 2149:  // デッドマン・ワンダーランド
            return 1358;
        case 2118:  // へうげもの
            return 1777;
        case 2139:  // 神のみぞ知るセカイII
            return 462;
        case 2137:  // 電波女と青春男
            return 1398;
        case 2110:  // けんぷファー fur die Liebe
            return 671;
        case 2132:  // プリティーリズム・オーロラドリーム
            return 1919;
        case 2116:  // 日常
            return 1540;
        case 3328:  // 塔の上のラプンツェル
            return 8076;
        case 3298:  // 手塚治虫のブッダ -赤い砂漠よ！美しく-
            return 3473;
        case 2135:  // 花咲くいろは
            return 1732;
        case 2111:  // まりあ†ほりっく あらいぶ
            return 2040;
        case 2553:  // 星を追う子ども
            return 3680;
        case 2125:  // 緋弾のアリア
            return 1820;
        case 2160:  // [ C ] THE MONEY OF SOUL AND POSSIBILITY CONTROL
            return 867;
        case 2134:  // Aチャンネル
            return 247;
        case 2172:  // 銀魂’
            return 611;
        case 2144:  // SKET DANCE
            return 1001;
        case 2190:  // イナズマイレブンGO
            return 147;
        case 2141:  // 俺たちに翼はない
            return 337;
        case 2123:  // 青の祓魔師
            return 123;
        case 2166:  // 逆境無頼カイジ 破戒録篇
            return 589;
        case 2117:  // 30歳の保健体育
            return 788;
        case 2120:  // アスタロッテのおもちゃ！
            return 65;
        case 2156:  // あの日見た花の名前を僕達はまだ知らない。
            return 43;
        case 2150:  // ジュエルペット サンシャイン
            return 909;
        case 2449:  // プリキュアオールスターズDX3 未来にとどけ！世界をつなぐ☆虹色の花
            return 3632;
        case 2197:  // トワノクオン
            return 3480;
        case 2136:  // 世界一初恋
            return 1094;
        case 2140:  // 星空へ架かる橋
            return 2012;
        case 2142:  // Steins;Gate
            return 865;
        case 2162:  // トリコ
            return 1447;
        case 2219:  // かってに改蔵
            return 2600;
        case 2167:  // 殿といっしょ ～眼帯の野望～
            return 1485;
        case 2179:  // フジログ シーズン1
            return 5885;
        case 2663:  // 少年マイロの火星冒険記
            return 8092;
        case 2157:  // ファイアボール チャーミング
            return 1885;
        case 2113:  // 変ゼミ
            return 1955;
        case 2169:  // メタルファイト ベイブレード 4D
            return 2208;
        case 2099:  // もしドラ
            return 2220;
        case 2161:  // 遊☆戯☆王ZEXAL
            return 2303;
        case 2147:  // よんでますよ、アザゼルさん。
            return 2313;
        case 2227:  // あそびにいくヨ！OVAすぺしゃる
            return 4536;
        case 2314:  // 装甲騎兵ボトムズ 孤影再び
            return 6380;
        case 2316:  // ボトムズファインダー
            return 6387;

        // 2011年夏
        case 2864:  // コクリコ坂から
            return 3303;
        case 2862:  // 劇場版 ハヤテのごとく！ HEAVEN IS A PLACE ON EARTH
            return 3592;
        case 2206:  // 猫神やおよろず
            return 1559;
        case 2628:  // 劇場版ポケットモンスター ベストウイッシュ ビクティニと白き英雄 レシラム
            return 3674;
        case 2216:  // 森田さんは無口。
            return 2246;
        case 2196:  // 神様ドォルズ
            return 465;
        case 2225:  // 輪るピングドラム
            return 2086;
        case 2233:  // Baby Princess 3Dぱらだいす0
            return 3002;
        case 2208:  // 神様のメモ帳
            return 463;
        case 2193:  // ゆるゆり
            return 2277;
        case 2629:  // 劇場版ポケットモンスター ベストウイッシュ ビクティニと黒き英雄 ゼクロム
            return 3675;
        case 2213:  // セイクリッドセブン
            return 1077;
        case 2198:  // まよチキ！
            return 2038;
        case 2868:  // カーズ2
            return 8105;
        case 2210:  // いつか天魔の黒ウサギ
            return 135;
        case 2195:  // BLOOD-C
            return 1842;
        case 2203:  // ダンタリアンの書架
            return 1223;
        case 2649:  // 劇場版 NARUTO -ナルト- ブラッド・プリズン
            return 3549;
        case 4817:  // Carnival Phantasm
            return 2595;
        case 2215:  // ぬらりひょんの孫 千年魔京
            return 1547;
        case 2209:  // ロウきゅーぶ！
            return 2432;
        case 2220:  // うさぎドロップ
            return 192;
        case 2204:  // 快盗天使ツインエンジェル ～キュンキュン☆ときめきパラダイス!!～
            return 444;
        case 2205:  // バカとテストと召喚獣にっ！
            return 1649;
        case 2547:  // ひぐらしのなく頃に煌
            return 2953;
        case 2200:  // うたの☆プリンスさまっ♪ マジLOVE1000％
            return 194;
        case 2217:  // R-15
            return 13;
        case 2221:  // NO.6
            return 1497;
        case 2211:  // 夏目友人帳 参
            return 1514;
        case 2199:  // にゃんぱいあ The Animation
            return 1527;
        case 2872:  // 蛍火の杜へ
            return 3682;
        case 2279:  // バトルスピリッツ 覇王
            return 1664;
        case 2427:  // こぴはん
            return 3801;
        case 2636:  // 薄桜鬼 雪華録
            return 2941;
        case 2214:  // 魔乳秘剣帖
            return 2088;
        case 2212:  // モンハン日記 ぎりぎりアイルー村G
            return 2240;

        // 2011年秋
        case 2259:  // ギルティクラウン
            return 530;
        case 2249:  // WORKING´!!
            return 2460;
        case 2306:  // 森田さんは無口。2
            return 5591;
        case 2270:  // 僕は友達が少ない
            return 1997;
        case 2252:  // 侵略！？イカ娘
            return 919;
        case 2808:  // 劇場版イナズマイレブンGO 究極の絆 グリフォン
            return 3150;
        case 2295:  // バクマン。2
            return 1651;
        case 2384:  // 京騒戯画 第一弾
            return 3798;
        case 2307:  // 戦国☆パラダイス-極-
            return 1107;
        case 2322:  // ちび☆デビ！
            return 4011;
        case 2274:  // C3 -シーキューブ-
            return 853;
        case 2273:  // 未来日記
            return 2165;
        case 2246:  // ひだまりスケッチ×SP
            return 1763;
        case 2271:  // ちはやふる
            return 1261;
        case 2335:  // この男子、宇宙人と戦えます。
            return 2697;
        case 2262:  // 灼眼のシャナⅢ Final
            return 967;
        case 2263:  // たまゆら～hitotose～
            return 1201;
        case 2774:  // ルパン三世 血の刻印～永遠のMermaid～
            return 2401;
        case 2288:  // HUNTER×HUNTER(2011)
            return 1593;
        case 2763:  // 映画スイートプリキュア♪とりもどせ！心がつなぐ奇跡のメロディ♪
            return 3369;
        case 2297:  // gdgd妖精s
            return 619;
        case 2253:  // ラストエグザイル -銀翼のファム-
            return 2345;
        case 2258:  // UN-GO
            return 18;
        case 2254:  // 境界線上のホライゾン
            return 550;
        case 2294:  // 世界一初恋2
            return 1095;
        case 2879:  // とある飛空士への追憶
            return 3476;
        case 2266:  // 機動戦士ガンダムAGE
            return 565;
        case 2300:  // フジログ シーズン2
            return 5886;
        case 2272:  // 君と僕。
            return 542;
        case 2257:  // ファイ・ブレイン 神のパズル
            return 1888;
        case 2299:  // クロスファイト ビーダマン
            return 638;
        case 2275:  // ベン・トー
            return 1953;
        case 2269:  // マケン姫っ！
            return 2050;
        case 2276:  // 真剣で私に恋しなさい！！
            return 2082;
        case 2298:  // デュエル・マスターズ ビクトリー
            return 5061;

        // 2011年冬
        case 2283:  // コイ☆セント
            return 2700;
        case 2284:  // ノラゲキ！
            return 2915;
        case 2853:  // ドラえもん 新・のび太と鉄人兵団 ～はばたけ天使たち～
            return 3512;
        case 2765:  // IS＜インフィニット・ストラトス＞アンコール 恋に焦がれる六重奏
            return 2531;
        case 2151:  // T.P.さくら ～タイムパラディンさくら～
            return 2814;
        case 2878:  // 劇場版アニメ　忍たま乱太郎　忍術学園　全員出動!の段
            return 3564;
        case 2754:  // 劇場版 マクロスF 恋離飛翼～サヨナラノツバサ～
            return 3694;
        case 2127:  // おぢいさんのランプ
            return 3185;
        case 2076:  // べるぜバブ
            return 1944;
        case 2069:  // 君に届け 2ND SEASON
            return 545;
        case 2071:  // Rio RainbowGate!
            return 2355;
        case 2075:  // これはゾンビですか？
            return 733;
        case 2091:  // レベルE
            return 2422;
        case 2087:  // みつどもえ 増量中！
            return 2137;
        case 2126:  // 万能野菜 ニンニンマン
            return 3590;
        case 2077:  // 魔法少女まどか☆マギカ
            return 2108;
        case 2096:  // ウルヴァリン
            return 216;
        case 2155:  // .hack//Quantum
            return 2867;
        case 2088:  // カードファイト!! ヴァンガード
            return 401;
        case 2145:  // バカとテストと召喚獣 ～祭～
            return 2932;
        case 2081:  // IS＜インフィニット・ストラトス＞
            return 128;
        case 2114:  // ダンボール戦機
            return 1224;
        case 2104:  // スイートプリキュア♪
            return 1014;
        case 2084:  // お兄ちゃんのことなんかぜんぜん好きじゃないんだからねっ！！
            return 325;
        case 2073:  // GOSICK―ゴシック―
            return 715;
        case 2315:  // 装甲騎兵ボトムズ Case;IRVINE
            return 6386;
        case 2191:  // 祝福のカンパネラ OVA
            return 4041;
        case 2072:  // ドラゴンクライシス！
            return 1461;
        case 2109:  // 放課後のプレアデス
            return 3822;
        case 2094:  // フラクタル – FRACTALE –
            return 1901;
        case 2074:  // フリージング
            return 1903;
        case 2093:  // 放浪息子
            return 2009;
        case 2089:  // 夢喰いメリー
            return 2296;
        case 2321:  // 聖闘士星矢 THE LOST CANVAS 冥王神話 第2章
            return 7148;
        case 2129:  // たんすわらし。
            return 3434;

        // 2012年春
        case 2503:  // シャイニング・ハーツ ～幸せのパン～
            return 890;
        case 2492:  // さんかれあ
            return 812;
        case 2542:  // イナズマイレブンGO クロノ・ストーン
            return 148;
        case 2466:  // アクセル・ワールド
            return 64;
        case 2500:  // Fate/Zero 2ndシーズン
            return 1856;
        case 2473:  // クイーンズブレイド リベリオン
            return 629;
        case 2506:  // GON -ゴン-
            return 714;
        case 2996:  // クレヨンしんちゃん 嵐を呼ぶ！オラと宇宙のプリンセス
            return 3267;
        case 2512:  // ふるさと再生 日本の昔ばなし
            return 4012;
        case 2518:  // 坂道のアポロン
            return 837;
        case 2477:  // ヨルムンガンド
            return 2317;
        case 2554:  // キングダム
            return 516;
        case 2478:  // 宇宙兄弟
            return 227;
        case 2481:  // 聖闘士星矢Ω
            return 1142;
        case 2510:  // しばいぬ子さん
            return 872;
        case 2519:  // つり球
            return 1314;
        case 2511:  // LUPIN the Third -峰不二子という女-
            return 2375;
        case 2479:  // 黒魔女さんが通る！！
            return 663;
        case 2494:  // リコーダーとランドセル レ♪
            return 2359;
        case 2505:  // あらしのよるに ～ひみつのともだち～
            return 48;
        case 2495:  // 氷菓
            return 1808;
        case 2470:  // 咲-Saki- 阿知賀編 episode of side-A
            return 836;
        case 2467:  // 夏色キセキ
            return 1516;
        case 2513:  // ロック・リーの青春フルパワー忍伝
            return 2443;
        case 2532:  // 秘密結社 鷹の爪 NEO
            return 1818;
        case 2522:  // しろくまカフェ
            return 878;
        case 2491:  // 這いよれ！ニャル子さん
            return 1740;
        case 2490:  // これはゾンビですか？ OF THE DEAD
            return 734;
        case 2485:  // 黒子のバスケ
            return 660;
        case 2496:  // ジュエルペット きら☆デコッ！
            return 907;
        case 2610:  // ポケットモンスター ベストウイッシュ シーズン2
            return 4013;
        case 2471:  // エウレカセブンAO
            return 267;
        case 2457:  // 謎の彼女X
            return 1520;
        case 2452:  // 映画プリキュアオールスターズNewStage みらいのともだち
            return 3643;
        case 2523:  // 銀河へキックオフ!!
            return 595;
        case 2484:  // ZETMAN
            return 1074;
        case 2486:  // 戦国コレクション
            return 1108;
        case 3000:  // ストライクウィッチーズ 劇場版
            return 3357;
        case 2468:  // 黄昏乙女×アムネジア
            return 1256;
        case 3090:  // 劇場版 BLOOD-C The Last Dark
            return 3636;
        case 2489:  // あっちこっち
            return 40;
        case 2545:  // うぽって!!
            return 203;
        case 2474:  // AKB0048
            return 242;
        case 2507:  // 君と僕。2
            return 543;
        case 2459:  // 緋色の欠片
            return 1821;
        case 2472:  // ガッ活！
            return 409;
        case 2536:  // ファイ・ブレイン 神のパズル(第2シリーズ)
            return 1889;
        case 2483:  // プリティーリズム・ディアマイフューチャー
            return 1920;
        case 2475:  // めだかボックス
            return 2201;
        case 2514:  // メタルファイト ベイブレード ZEROG
            return 2209;
        case 2476:  // ゆるめいつ 3でぃ 
            return 2275;
        case 3003:  // 図書館戦争 革命のつばさ
            return 3544;
        case 2960:  // ももへの手紙
            return 3741;
        case 2516:  // カードファイト!! ヴァンガード アジアサーキット編
            return 5940;

        // 2012年夏
        case 2574:  // 輪廻のラグランジェ season2
            return 2373;
        case 2567:  // ゆるゆり♪♪
            return 2278;
        case 2666:  // 探偵オペラ ミルキィホームズ Alternative ONE 小林オペラと5枚の絵画
            return 1238;
        case 2576:  // ちとせげっちゅ！！
            return 1260;
        case 2597:  // 夏雪ランデブー
            return 1517;
        case 2586:  // トータル・イクリプス
            return 1449;
        case 2596:  // 探検ドリランド
            return 1243;
        case 2575:  // だから僕は、Hができない。
            return 1205;
        case 2588:  // ソードアート・オンライン
            return 1166;
        case 2920:  // 今日のあすかショー
            return 5164;
        case 2504:  // グスコーブドリの伝記
            return 3274;
        case 2898:  // コードギアス 亡国のアキト 第1章 翼竜は舞い降りた
            return 3304;
        case 2594:  // アルカナ・ファミリア
            return 83;
        case 2644:  // おおかみこどもの雨と雪
            return 3184;
        case 2590:  // じょしらく
            return 881;
        case 2585:  // ココロコネクト
            return 741;
        case 2593:  // TARI TARI
            return 1191;
        case 2595:  // DOG DAYS'
            return 1405;
        case 2577:  // 恋と選挙とチョコレート
            return 768;
        case 2605:  // 境界線上のホライゾンⅡ
            return 551;
        case 3081:  // メロエッタのキラキラリサイタル
            return 3718;
        case 3285:  // 劇場版 TIGER & BUNNY -The Beginning-
            return 3437;
        case 4582:  // 魔法少女リリカルなのは The MOVIE 2nd A's
            return 3703;
        case 2587:  // 人類は衰退しました
            return 917;
        case 2571:  // カンピオーネ！ ～まつろわぬ神々と神殺しの魔王～
            return 399;
        case 2592:  // この中に1人、妹がいる！
            return 726;
        case 2634:  // 乃木坂春香の秘密 ふぃな～れ♪
            return 2917;
        case 2721:  // たまごっち！ゆめキラドリーム
            return 1200;
        case 3270:  // 劇場版 FAIRY TAIL 鳳凰の巫女
            return 3637;
        case 2604:  // 超訳百人一首 うた恋い。
            return 1303;
        case 2591:  // 乙女はお姉さまに恋してる ～2人のエルダー～ THE ANIMATION
            return 2592;
        case 2572:  // 織田信奈の野望
            return 350;
        case 2646:  // ROAD TO NINJA -NARUTO THE MOVIE-
            return 3773;
        case 2599:  // 薄桜鬼 黎明録
            return 1737;
        case 2734:  // 緋色の欠片 第二章
            return 1822;
        case 2589:  // 貧乏神が！
            return 1830;
        case 2584:  // はぐれ勇者の鬼畜美学
            return 1604;
        case 2648:  // マジでオタクなイングリッシュ！りぼんちゃん～英語で戦う魔法少女～
            return 2057;
        case 2602:  // もやしもん リターンズ
            return 2225;
        case 2583:  // ゆるめいつ 3でぃ PLUS
            return 2276;
        case 2711:  // バトルスピリッツ ソードアイズ
            return 1660;
        case 2710:  // ピムとポムのちっちゃな冒険
            return 6485;
        case 2682:  // ONE PIECE エピソードオブナミ 〜航海士の涙と仲間の絆〜
            return 7139;

        // 2012年秋
        case 2735:  // PSYCHO-PASS サイコパス
            return 792;
        case 2755:  // ルパン三世 東方見聞録～アナザーページ～
            return 2397;
        case 2719:  // BTOOOM!
            return 1850;
        case 2758:  // ライチ DE 光クラブ
            return 2344;
        case 3198:  // 映画スマイルプリキュア！絵本の中はみんなチグハグ！
            return 3370;
        case 2731:  // CODE:BREAKER
            return 711;
        case 2724:  // 遊☆戯☆王 ZEXAL II
            return 4014;
        case 2705:  // To LOVEる-とらぶる- ダークネス
            return 1413;
        case 3491:  // マクロスFB7 銀河流魂 オレノウタヲキケ！
            return 3687;
        case 2633:  // わんおふ -one off-
            return 2466;
        case 2783:  // 蒼い世界の中心で
            return 109;
        case 2749:  // ぴっちぴち♪しずくちゃん
            return 1776;
        case 2712:  // めだかボックス アブノーマル
            return 2202;
        case 2801:  // 劇場版 イナズマイレブンGO VS ダンボール戦機W
            return 3148;
        case 2741:  // バクマン。3
            return 1652;
        case 2715:  // ROBOTICS;NOTES
            return 2429;
        case 3513:  // ヱヴァンゲリヲン 新劇場版：Q
            return 3179;
        case 2729:  // 獣旋バトル モンスーノ
            return 970;
        case 2733:  // ヨルムンガンド PERFECT ORDER
            return 2318;
        case 2732:  // ジョジョの奇妙な冒険
            return 911;
        case 2694:  // 絶園のテンペスト
            return 1131;
        case 2726:  // 超速変形ジャイロゼッター
            return 1305;
        case 2722:  // アイカツ！-アイドルカツドウ！-
            return 51;
        case 2665:  // さくら荘のペットな彼女
            return 804;
        case 2730:  // イクシオン サーガ DT
            return 140;
        case 3309:  // 探偵オペラ ミルキィホームズ Alternative TWO 小林オペラと虚空の大鴉
            return 1239;
        case 2762:  // 銀魂’ 延長戦
            return 592;
        case 2643:  // えびてん 公立海老栖川高校天悶部
            return 261;
        case 2704:  // リトルバスターズ！
            return 2362;
        case 2738:  // マギ The labyrinth of magic
            return 2047;
        case 2743:  // うーさーのその日暮らし
            return 207;
        case 5496:  // 神のみぞ知るセカイ 天理篇
            return 2622;
        case 2881:  // この男子、人魚ひろいました。
            return 2696;
        case 2742:  // てーきゅう
            return 1340;
        case 2717:  // 新世界より
            return 953;
        case 3269:  // 009 RE:CYBORG
            return 3372;
        case 2744:  // 伏 鉄砲娘の捕物帳
            return 3634;
        case 2691:  // ガールズ&パンツァー
            return 424;
        case 2714:  // 神様はじめました
            return 464;
        case 2709:  // 中二病でも恋がしたい！
            return 1276;
        case 2728:  // 好きっていいなよ。
            return 1059;
        case 2827:  // 華ヤカ哉、我ガ一族 キネトグラフ
            return 2940;
        case 2736:  // となりの怪物くん
            return 1429;
        case 2696:  // お兄ちゃんだけど愛さえあれば関係ないよねっ
            return 324;
        case 2846:  // はいたい七葉
            return 1601;
        case 2716:  // K
            return 667;
        case 2679:  // ひだまりスケッチ×ハニカム
            return 1766;
        case 2740:  // クロスファイト ビーダマンeS
            return 639;
        case 2683:  // 武装神姫
            return 1933;
        case 2852:  // ONE PIECE エピソードオブルフィ 〜ハンドアイランドの冒険〜
            return 7140;
        case 2720:  // ハヤテのごとく！CAN'T TAKE MY EYES OFF YOU
            return 1638;

        // 2012年冬
        case 2363:  // リコーダーとランドセル ド♪
            return 2357;
        case 2419:  // ドットハック セカイの向こうに
            return 3481;
        case 3224:  // ToHeart2 ダンジョントラベラーズ
            return 2875;
        case 2396:  // 偽物語
            return 1534;
        case 2370:  // モーレツ宇宙海賊
            return 2241;
        case 2378:  // アクエリオンEVOL
            return 63;
        case 2365:  // ゼロの使い魔F
            return 1088;
        case 2815:  // 僕の妹は「大阪おかん」
            return 1996;
        case 2375:  // 戦姫絶唱シンフォギア
            return 1113;
        case 2373:  // Another
            return 4;
        case 2435:  // ダンボール戦機W
            return 1225;
        case 2382:  // BRAVE10
            return 1847;
        case 2386:  // 男子高校生の日常
            return 1249;
        case 2377:  // 妖狐×僕SS
            return 162;
        case 2374:  // アマガミSS+ plus
            return 77;
        case 2368:  // あの夏で待ってる
            return 42;
        case 2390:  // 輪廻のラグランジェ
            return 2372;
        case 2418:  // 新テニスの王子様
            return 948;
        case 2359:  // 探偵オペラ ミルキィホームズ 第2幕
            return 1240;
        case 2425:  // エリアの騎士
            return 271;
        case 2413:  // スマイルプリキュア！
            return 1041;
        case 2366:  // ハイスクールD×D
            return 1622;
        case 2372:  // キルミーベイベー
            return 514;
        case 2407:  // テルマエ・ロマエ
            return 1347;
        case 2367:  // 夏目友人帳 肆
            return 1515;
        case 2840:  // 猫物語(黒)
            return 1558;
        case 2383:  // パパのいうことを聞きなさい！
            return 1684;
        case 5403:  // マジック・ツリーハウス
            return 8300;
        case 2433:  // ゴクジョッ。～極楽院女子高寮物語～
            return 754;
        case 2397:  // ブラック★ロックシューター(TVシリーズ)
            return 1911;
        case 2389:  // ポヨポヨ観察日記
            return 1992;
        case 2886:  // Aチャンネル +smile
            return 4534;
        case 2460:  // BUTA
            return 6053;
        case 2461:  // わすれなぐも
            return 6054;
        case 2463:  // しらんぷり
            return 6055;
        case 2437:  // 秘密結社 鷹の爪外伝 むかしの吉田くん
            return 6865;
        case 2462:  // ぷかぷかジュジュ
            return 6056;

        // 2013年春
        case 2940:  // スパロウズホテル
            return 1038;
        case 3664:  // 夏目友人帳 ニャンコ先生とはじめてのおつかい
            return 4322;
        case 2921:  // RDG レッドデータガール
            return 2412;
        case 2919:  // 這いよれ！ニャル子さんW
            return 1741;
        case 3405:  // クレヨンしんちゃん バカうまっ！B級グルメサバイバル！！
            return 3256;
        case 3492:  // 言の葉の庭
            return 3312;
        case 2976:  // すすめ！キッチン戦隊クックルン
            return 4015;
        case 2929:  // 惡の華
            return 96;
        case 2933:  // 映画プリキュアオールスターズNewStage2 こころのともだち
            return 3644;
        case 2950:  // マイリトルポニー ～トモダチは魔法～
            return 2045;
        case 2939:  // ムシブギョー
            return 2175;
        case 2973:  // ダンボール戦機WARS
            return 1226;
        case 3951:  // ちいさなプリンセス ソフィア
            return 4506;
        case 3229:  // AURA ～魔竜院光牙最後の闘い～
            return 3121;
        case 2945:  // 波打際のむろみさん
            return 1519;
        case 2988:  // デュエル・マスターズ ビクトリーＶ3
            return 4018;
        case 2954:  // 絶対防衛レヴィアタン
            return 1135;
        case 2917:  // 銀河機攻隊 マジェスティックプリンス
            return 599;
        case 2911:  // やはり俺の青春ラブコメはまちがっている。
            return 2255;
        case 2972:  // LINE TOWN
            return 4017;
        case 2947:  // 翠星のガルガンティア
            return 1067;
        case 2949:  // 団地ともお
            return 1228;
        case 2943:  // ゆゆ式
            return 2274;
        case 2986:  // 秘密結社 鷹の爪 MAX
            return 1817;
        case 3008:  // イナズマイレブンGO ギャラクシー
            return 4019;
        case 2941:  // あいうら
            return 24;
        case 2953:  // ジュエルペット ハッピネス
            return 910;
        case 3494:  // 劇場版 Steins;Gate 負荷領域のデジャヴ
            return 3329;
        case 2926:  // 変態王子と笑わない猫。
            return 1956;
        case 2498:  // 宇宙戦艦ヤマト2199 (TVシリーズ)
            return 231;
        case 2910:  // デート・ア・ライブ
            return 1367;
        case 2925:  // はたらく魔王さま！
            return 1610;
        case 3010:  // 天使のどろっぷ
            return 1379;
        case 2966:  // ぢべたぐらし あひるの生活
            return 1267;
        case 2989:  // 鉄人28号ガオ！
            return 1391;
        case 2935:  // 進撃の巨人
            return 997;
        case 2946:  // DEVIL SURVIVOR 2 THE ANIMATION
            return 1330;
        case 3002:  // イケメン救護隊 ナースエンジェルス
            return 7129;
        case 2936:  // 革命機ヴァルヴレイヴ
            return 475;
        case 2969:  // 血液型くん！
            return 708;
        case 2937:  // とある科学の超電磁砲S
            return 1420;
        case 2932:  // アラタカンガタリ～革神語～
            return 78;
        case 2916:  // 俺の妹がこんなに可愛いわけがない。
            return 339;
        case 3183:  // マジカル☆スター かのん100％
            return 3036;
        case 2956:  // ロボカーポリー
            return 4016;
        case 2955:  // プリティーリズム・レインボーライブ
            return 1921;
        case 2975:  // 探検ドリランド-1000年の真宝-
            return 1244;
        case 2938:  // 断裁分離のクライムエッジ
            return 1245;
        case 2952:  // DD北斗の拳
            return 1326;
        case 3034:  // キングダム 第2シリーズ
            return 517;
        case 2967:  // ガラスの仮面ですが
            return 415;
        case 3230:  // 聖☆おにいさん
            return 3379;
        case 3493:  // ハル
            return 3582;
        case 2928:  // ハヤテのごとく！Cuties
            return 1639;
        case 3005:  // 宮河家の空腹
            return 3825;
        case 2948:  // うたの☆プリンスさまっ♪ マジLOVE2000％
            return 195;
        case 2930:  // 百花繚乱 サムライブライド
            return 1814;
        case 2912:  // カーニヴァル
            return 403;
        case 2978:  // ガッ活！第2シリーズ
            return 410;
        case 2934:  // フォトカノ
            return 1895;
        case 3079:  // はいたい七葉 第2期
            return 1602;
        case 2964:  // ぼくは王さま
            return 1971;
        case 2931:  // よんでますよ、アザゼルさん。Z
            return 2314;
        case 2999:  // ガラスの仮面ですがZ
            return 5921;

        // 2013年夏
        case 5676:  // SHORT PEACE
            return 3323;
        case 3145:  // DIABOLIK LOVERS
            return 1331;
        case 3489:  // 小鳥遊六花・改 ～劇場版 中二病でも恋がしたい！～
            return 3439;
        case 3021:  // きんいろモザイク
            return 491;
        case 3495:  // 空の境界 未来福音
            return 3215;
        case 3035:  // Fate/kaleid liner プリズマ☆イリヤ
            return 1853;
        case 3047:  // ガッチャマン クラウズ
            return 408;
        case 3052:  // 魔界王子 devils and realist
            return 2125;
        case 3020:  // たまゆら～もあぐれっしぶ～
            return 1202;
        case 3058:  // 戦勇。 第2期
            return 1104;
        case 3042:  // 恋愛ラボ
            return 2352;
        case 3012:  // ＜物語＞シリーズ セカンドシーズン
            return 2252;
        case 3040:  // ロウきゅーぶ！SS
            return 2433;
        case 3483:  // 劇場版ポケットモンスター ベストウイッシュ 神速のゲノセクト ミュウツー覚醒
            return 3676;
        case 3037:  // 幻影ヲ駆ケル太陽
            return 697;
        case 3041:  // ステラ女学院高等科C3部
            return 1028;
        case 3667:  // 風立ちぬ
            return 3219;
        case 3027:  // 神のみぞ知るセカイ 女神篇
            return 461;
        case 3019:  // 犬とハサミは使いよう
            return 164;
        case 3015:  // ローゼンメイデン (2013)
            return 2450;
        case 3053:  // 八犬伝 -東方八犬異聞- 第二期
            return 1694;
        case 3055:  // BROTHERS CONFLICT
            return 1849;
        case 4672:  // 劇場版 あの日見た花の名前を僕達はまだ知らない。
            return 3139;
        case 3045:  // 帰宅部活動記録
            return 555;
        case 3496:  // 空の境界 未来福音 extra chorus
            return 3216;
        case 3028:  // 私がモテないのはどう考えてもお前らが悪い！
            return 2479;
        case 3016:  // サーバント×サービス
            return 829;
        case 3043:  // ダンガンロンパ 希望の学園と絶望の高校生 The Animation
            return 1221;
        case 3031:  // Free!
            return 1860;
        case 3023:  // 君のいる町
            return 546;
        case 3157:  // Super Seisyun Brothers -超青春姉弟s-
            return 1009;
        case 3013:  // 戦姫絶唱シンフォギアG
            return 1114;
        case 3026:  // リコーダーとランドセル ミ☆
            return 2358;
        case 3038:  // ハイスクールD×D NEW
            return 1623;
        case 5893:  // 劇場版 銀魂 完結篇 万事屋よ永遠なれ
            return 3231;
        case 3039:  // 神さまのいない日曜日
            return 459;
        case 3029:  // 有頂天家族
            return 235;
        case 3014:  // 超次元ゲイム ネプテューヌ THE ANIMATION
            return 1295;
        case 3083:  // 劇場版 薄桜鬼
            return 3594;
        case 3044:  // ふたりはミルキィホームズ
            return 1877;
        case 3056:  // 義風堂々！！ 兼続と慶次 
            return 587;
        case 3046:  // 銀の匙 Silver Spoon
            return 593;
        case 3036:  // ブラッドラッド
            return 1913;
        case 3071:  // 闇芝居（1期）
            return 5911;
        case 3061:  // マジでオタクなイングリッシュ！りぼんちゃん the TV
            return 2056;
        case 3062:  // にゅるにゅる!!KAKUSENくん (第1期)
            return 5925;
        case 3030:  // ファンタジスタドール
            return 1891;
        case 3584:  // Go!Go!家電男子 シーズン1
            return 5923;

        // 2013年秋
        case 3206:  // はじめの一歩 Rising
            return 1607;
        case 3654:  // ルパン三世VS名探偵コナン THE MOVIE
            return 3769;
        case 3160:  // キルラキル KILL la KILL
            return 515;
        case 3184:  // COPPELION
            return 712;
        case 3219:  // ひだまりスケッチ 沙英・ヒロ 卒業編
            return 2955;
        case 3159:  // 弱虫ペダル
            return 2328;
        case 3136:  // 蒼き鋼のアルペジオ -アルス･ノヴァ-
            return 112;
        case 3188:  // ガンダムビルドファイターズ
            return 419;
        case 3186:  // ダイヤのA
            return 1218;
        case 3165:  // ゴールデンタイム
            return 762;
        case 3503:  // 魔女っこ姉妹のヨヨとネネ
            return 3700;
        case 3727:  // ポンコツクエスト～魔王と派遣の魔物たち～
            return 4392;
        case 3144:  // 俺の脳内選択肢が、学園ラブコメを全力で邪魔している
            return 341;
        case 3162:  // 京騒戯画
            return 533;
        case 3166:  // アウトブレイク・カンパニー
            return 56;
        case 3156:  // ミス・モノクローム -The Animation- 
            return 2148;
        case 3142:  // IS＜インフィニット・ストラトス＞2
            return 129;
        case 3143:  // 機巧少女は傷つかない
            return 2079;
        case 3497:  // BAYONETTA Bloody Fate
            return 3860;
        case 3193:  // マギ The kingdom of magic
            return 2046;
        case 3141:  // ストライク・ザ・ブラッド
            return 1032;
        case 3155:  // ぎんぎつね
            return 493;
        case 5925:  // PERSONA3 THE MOVIE
            return 3646;
        case 3137:  // のんのんびより
            return 1570;
        case 3161:  // 凪のあすから
            return 1509;
        case 3194:  // サラとダックン
            return 4021;
        case 3203:  // てさぐれ！部活もの
            return 1339;
        case 3152:  // リトルバスターズ！～Refrain～
            return 2363;
        case 3167:  // 東京レイヴンズ
            return 1480;
        case 3158:  // WHITE ALBUM2
            return 1965;
        case 3187:  // 夜桜四重奏～ハナノウタ～
            return 2323;
        case 3222:  // ルパン三世 princess of the breeze 〜隠された空中都市〜
            return 2381;
        case 3176:  // ログ・ホライズン
            return 2434;
        case 3163:  // 境界の彼方
            return 549;
        case 3164:  // 最強銀河究極ゼロ ～バトルスピリッツ～
            return 842;
        case 3499:  // サカサマのパテマ
            return 3314;
        case 3191:  // ガリレイドンナ
            return 417;
        case 3153:  // 世界でいちばん強くなりたい！
            return 1093;
        case 3205:  // 声優戦隊ボイストーム7
            return 1102;
        case 3154:  // ワルキューレ ロマンツェ
            return 2469;
        case 3226:  // 熱風海陸ブシロード
            return 1557;
        case 3151:  // 勇者になれなかった俺はしぶしぶ就職を決意しました。
            return 2284;
        case 3192:  // サムライフラメンコ
            return 826;
        case 3182:  // ガイストクラッシャー
            return 406;
        case 3169:  // BLAZBLUE ALTER MEMORY
            return 1839;
        case 3177:  // ファイ・ブレイン 神のパズル(第3シリーズ)
            return 1890;
        case 3168:  // フリージング ヴァイブレーション
            return 1904;
        case 3204:  // 殺し屋さん
            return 778;
        case 3179:  // ポケットモンスター XY
            return 1984;
        case 3180:  // ポケットモンスター THE ORIGIN
            return 1983;
        case 3508:  // 映画ドキドキ！プリキュア マナ結婚!!?未来につなぐ希望のドレス!
            return 4297;
        case 3189:  // メガネブ！
            return 2205;
        case 3150:  // たまごっち！～みらくるフレンズ～
            return 4020;
        case 3659:  // 劇場版 HUNTER×HUNTER -The LAST MISSION-
            return 6090;

        // 2013年冬
        case 2836:  // 幕末義人伝 浪漫
            return 1701;
        case 2884:  // 石田とあさくら
            return 169;
        case 2817:  // 僕は友達が少ないNEXT
            return 1998;
        case 5023:  // ヴァンキッシュド・クイーンズ
            return 2556;
        case 3645:  // シュガー・ラッシュ
            return 8078;
        case 3647:  // くもりときどきミートボール２　フード・アニマル誕生の秘密
            return 8023;
        case 2883:  // ビーストサーガ
            return 1794;
        case 3637:  // がんばれ! おでんくん
            return 386;
        case 2819:  // 俺の彼女と幼なじみが修羅場すぎる
            return 340;
        case 2847:  // 戦勇。
            return 1103;
        case 2824:  // キューティクル探偵因幡
            return 510;
        case 3658:  // 劇場版 HUNTER×HUNTER 緋色の幻影
            return 3591;
        case 2944:  // 龍 -RYO-
            return 3761;
        case 3076:  // 劇場版 とある魔術の禁書目録 -エンデュミオンの奇蹟-
            return 3539;
        case 2842:  // まんがーる！
            return 2041;
        case 2825:  // たまこまーけっと
            return 1198;
        case 2889:  // LINE OFFLINE ～サラリーマン～
            return 2332;
        case 2903:  // 直球表題ロボットアニメ
            return 3892;
        case 2875:  // ちはやふる2
            return 1262;
        case 2806:  // あいまいみー
            return 25;
        case 2837:  // D.C.III ～ダ・カーポIII～
            return 1184;
        case 2845:  // ヤマノススメ
            return 2263;
        case 2871:  // がんばれ！ルルロロ
            return 390;
        case 2859:  // 八犬伝 -東方八犬異聞-
            return 1693;
        case 2818:  // ささみさん@がんばらない
            return 805;
        case 2776:  // 生徒会の一存 Lv.2
            return 1125;
        case 2838:  // まおゆう魔王勇者
            return 2021;
        case 2839:  // AKB0048 next stage
            return 243;
        case 2860:  // THE UNLIMITED 兵部京介
            return 866;
        case 2835:  // ビビッドレッド・オペレーション
            return 1788;
        case 2848:  // gdgd妖精s 第2期
            return 620;
        case 2887:  // ドキドキ！プリキュア
            return 1452;
        case 2861:  // AMNESIA
            return 3;
        case 2876:  // ぷちます！-プチ・アイドルマスター-
            return 3814;
        case 2821:  // みなみけ ただいま
            return 2141;
        case 2816:  // 問題児たちが異世界から来るそうですよ？
            return 2242;
        case 2814:  // 閃乱カグラ
            return 1144;
        case 2877:  // GJ部
            return 621;
        case 2844:  // ラブライブ！ School idol project
            return 2349;
        case 2942:  // デス・ビリヤード
            return 3461;
        case 3856:  // ヘタリア The Beautiful World (第5期)
            return 3819;
        case 2882:  // カードファイト!! ヴァンガード リンクジョーカー編
            return 402;
        case 2834:  // 琴浦さん
            return 779;

        // 2014年春
        case 3369:  // GO‐GO たまごっち！
            return 4058;
        case 3319:  // 棺姫のチャイカ
            return 3975;
        case 3362:  // ピンポン THE ANIMATION
            return 4002;
        case 3315:  // 一週間フレンズ。
            return 3969;
        case 3390:  // 監督不行届
            return 4053;
        case 3351:  // 遊☆戯☆王ARC‐V
            return 3967;
        case 3339:  // 悪魔のリドル
            return 3993;
        case 3336:  // ソウルイーターノット！
            return 3977;
        case 3344:  // 召しませロードス島戦記～それっておいしいの？
            return 4055;
        case 3327:  // 蟲師 続章
            return 3995;
        case 3333:  // メカクシティアクターズ
            return 3982;
        case 3772:  // クレヨンしんちゃん ガチンコ！逆襲のロボとーちゃん
            return 4071;
        case 3378:  // ブレイク ブレイド
            return 3968;
        case 3368:  // ポケットモンスター XY特別編 最強メガシンカ ～Act I～
            return 4057;
        case 3308:  // ナンダカベロニカ
            return 3947;
        case 3346:  // マジンボーン
            return 3950;
        case 4669:  // 頭文字D Final Stage
            return 4532;
        case 3387:  // ドラゴンボール改（魔人ブウ編）
            return 3964;
        case 3407:  // ロボカーポリー(第2期)
            return 4116;
        case 3783:  // たまこラブストーリー
            return 4068;
        case 3383:  // 金田一少年の事件簿R
            return 3959;
        case 3385:  // FAIRY TAIL(第2期)
            return 3980;
        case 3338:  // 僕らはみんな河合荘
            return 3979;
        case 3561:  // 猫のダヤン
            return 4295;
        case 3347:  // テンカイナイト
            return 3956;
        case 3323:  // エスカ＆ロジーのアトリエ ～黄昏の空の錬金術士～
            return 4001;
        case 3377:  // それでも世界は美しい
            return 3962;
        case 3335:  // 龍ヶ嬢七々々の埋蔵金
            return 3981;
        case 3340:  // selector infected WIXOSS
            return 4003;
        case 3379:  // ケロロ
            return 3949;
        case 3311:  // わしも-wasimo-
            return 3946;
        case 3314:  // デート・ア・ライブII
            return 3976;
        case 3380:  // ハイキュー!!
            return 3965;
        case 3322:  // ノーゲーム・ノーライフ
            return 3989;
        case 3352:  // ヒーローバンク
            return 3973;
        case 3382:  // 暴れん坊力士!!松太郎
            return 3963;
        case 3321:  // ブラック・ブレット
            return 3991;
        case 3394:  // ぷちます!!-プチプチ・アイドルマスター-
            return 3951;
        case 3365:  // M3-ソノ黒キ鋼-
            return 4056;
        case 3313:  // 星刻の竜騎士
            return 3961;
        case 3363:  // シドニアの騎士
            return 3992;
        case 3320:  // ミュータント タートルズ(2014)
            return 3954;
        case 3375:  // プリティーリズム・オールスターセレクション
            return 3958;
        case 3350:  // オレカバトル
            return 3971;
        case 3364:  // 風雲維新ダイショーグン
            return 3987;
        case 3393:  // 秘密結社 鷹の爪 EX
            return 4007;
        case 5952:  // 名探偵コナン 異次元の狙撃手
            return 4070;
        case 3392:  // カリーノ・コニ
            return 4117;
        case 3329:  // 極黒のブリュンヒルデ
            return 3983;
        case 3555:  // ワールドフールニュース
            return 7135;
        case 3345:  // ベイビーステップ
            return 3966;
        case 3371:  // くつだる。
            return 3953;
        case 3317:  // ジョジョの奇妙な冒険 スターダストクルセイダース
            return 3955;
        case 3332:  // マンガ家さんとアシスタントさんと
            return 3984;
        case 3316:  // 彼女がフラグをおられたら
            return 3970;
        case 3334:  // 魔法科高校の劣等生
            return 3985;
        case 3324:  // ご注文はうさぎですか？
            return 3994;
        case 3357:  // 神々の悪戯
            return 3990;
        case 3337:  // ブレイドアンドソウル
            return 3998;
        case 3325:  // 犬神さんと猫山さん
            return 3999;
        case 3330:  // 戦国無双SP ～真田の章～
            return 3948;
        case 3356:  // レディ ジュエルペット
            return 3957;
        case 3331:  // ラブライブ！ School idol project (第2期)
            return 3996;
        case 3415:  // GJ部＠
            return 4004;
        case 3326:  // ディスク・ウォーズ：アベンジャーズ
            return 3952;
        case 3349:  // 健全ロボ ダイミダラー
            return 3960;
        case 3353:  // 史上最強の弟子ケンイチ 闇の襲撃
            return 3974;
        case 3341:  // キャプテン・アース
            return 3988;
        case 3381:  // 魔法少女大戦
            return 3986;
        case 3386:  // デュエル・マスターズ VS
            return 4118;
        case 3318:  // カードファイト!! ヴァンガード レギオンメイト編
            return 3945;
        case 3376:  // 金色のコルダ Blue♪Sky
            return 3978;
        case 3370:  // 超爆裂異次元メンコバトル ギガントシューター つかさ
            return 4059;
        case 3358:  // アルモニ
            return 4140;
        case 3304:  // 映画プリキュアオールスターズNewStage3 永遠のともだち
            return 4323;
        case 3804:  // Go!Go!家電男子 シーズン2
            return 5924;

        // 2014年夏
        case 3452:  // 美少女戦士セーラームーンCrystal
            return 4111;
        case 3479:  // フランチェスカ
            return 4133;
        case 3438:  // 普通の女子校生が【ろこどる】やってみた。
            return 4006;
        case 3484:  // 信長協奏曲
            return 4138;
        case 4830:  // 宇宙兄弟#0
            return 4129;
        case 3451:  // 人生相談テレビアニメーション「人生」
            return 4112;
        case 3454:  // 六畳間の侵略者!?
            return 4105;
        case 3453:  // 少年ハリウッド -HOLLY STAGE FOR 49-
            return 4104;
        case 3634:  // スポチャン対決！～妖怪大決戦～
            return 8338;
        case 3420:  // ヤマノススメ セカンドシーズン
            return 4092;
        case 3443:  // スペース☆ダンディ シーズン2
            return 4083;
        case 3444:  // DRAMAtical Murder
            return 4082;
        case 3416:  // ソードアート・オンラインII
            return 4093;
        case 3434:  // プリパラ
            return 4096;
        case 3480:  // 闇芝居（2期）
            return 4135;
        case 3442:  // ばらかもん
            return 4084;
        case 3419:  // グラスリップ
            return 4099;
        case 3446:  // Fate/kaleid liner プリズマ☆イリヤ ツヴァイ！
            return 4080;
        case 3424:  // 月刊少女野崎くん
            return 4089;
        case 3421:  // アオハライド
            return 4097;
        case 3455:  // RAIL WARS!
            return 4110;
        case 4658:  // 思い出のマーニー
            return 4115;
        case 3423:  // 幕末Rock
            return 4090;
        case 3481:  // PSYCHO-PASS サイコパス 新編集版
            return 4134;
        case 3475:  // 残響のテロル
            return 4121;
        case 3440:  // ペルソナ4 ザ・ゴールデン
            return 4085;
        case 3458:  // ハナヤマタ
            return 4108;
        case 3445:  // 精霊使いの剣舞
            return 4081;
        case 3457:  // ひめゴト
            return 4107;
        case 3437:  // 東京喰種トーキョーグール
            return 4086;
        case 3459:  // あいまいみー ～妄想カタストロフ～
            return 4109;
        case 3487:  // みならいディーバ（※生アニメ）
            return 4132;
        case 3441:  // アルドノア・ゼロ
            return 4054;
        case 3427:  // アカメが斬る！
            return 4098;
        case 4415:  // 弱虫ペダル Re:RIDE
            return 4163;
        case 3462:  // LOVE STAGE!!
            return 4114;
        case 3476:  // 毎度！浦安鉄筋家族
            return 4136;
        case 3449:  // Free! -Eternal Summer-
            return 4100;
        case 3433:  // さばげぶっ！
            return 4087;
        case 3425:  // モモキュンソード
            return 4088;
        case 3436:  // 白銀の意思 アルジェヴォルン
            return 4094;
        case 3435:  // まじもじるるも
            return 4095;
        case 3466:  // ガンダムさん
            return 4119;
        case 3463:  // 真 ストレンジ・プラス
            return 4120;
        case 3857:  // ポケモン・ザ・ムービーXY 破壊の繭とディアンシー
            return 5004;
        case 3448:  // Re：␣ハマトラ
            return 4078;
        case 3447:  // 東京ESP
            return 4079;
        case 3422:  // 黒執事 Book of Circus
            return 4091;
        case 3456:  // 戦国BASARA Judge End
            return 4106;
        case 5805:  // LUPIN THE IIIRD 次元大介の墓標
            return 4124;
        case 3485:  // 目玉焼きの黄身 いつつぶす？
            return 4139;
        case 3878:  // STAND BY ME ドラえもん
            return 5132;

        // 2014年秋
        case 3544:  // Bonjour♪恋味パティスリー
            return 4169;
        case 3517:  // Hi☆sCoool! セハガール
            return 4201;
        case 3511:  // デンキ街の本屋さん
            return 4123;
        case 3519:  // がんばれ！ルルロロ(第2シリーズ)
            return 4214;
        case 3552:  // おしりかじり虫 第3シリーズ
            return 4222;
        case 3554:  // 怪盗ジョーカー
            return 4143;
        case 3509:  // 魔弾の王と戦姫
            return 4185;
        case 4010:  // 映画 妖怪ウォッチ 誕生の秘密だニャン！
            return 4610;
        case 3605:  // 宇宙戦艦ヤマト2199 星巡る方舟
            return 4213;
        case 3540:  // ワールドトリガー
            return 4195;
        case 3575:  // ナノ・インベーダーズ
            return 4223;
        case 3553:  // 曇天に笑う
            return 4150;
        case 3514:  // 俺、ツインテールになります。
            return 4174;
        case 3524:  // SHIROBAKO
            return 4168;
        case 3520:  // ふうせんいぬティニー
            return 4187;
        case 3534:  // オレん家のフロ事情
            return 4199;
        case 3550:  // ログ・ホライズン 第2シリーズ
            return 4208;
        case 3546:  // 四月は君の嘘
            return 4164;
        case 3551:  // 寄生獣 セイの格率
            return 4155;
        case 3502:  // ガールフレンド(仮)
            return 4128;
        case 3549:  // PSYCHO-PASS サイコパス 2
            return 4205;
        case 3505:  // 天体のメソッド
            return 4197;
        case 3527:  // 弱虫ペダル GRANDE ROAD
            return 4207;
        case 3523:  // 牙狼〈GARO〉-炎の刻印-
            return 4167;
        case 3530:  // TERRAFORMARS (テラフォーマーズ)
            return 4186;
        case 4399:  // ベイマックス
            return 8080;
        case 3512:  // 蟲師 続章(第2期)
            return 4220;
        case 3543:  // 神撃のバハムート GENESIS
            return 4161;
        case 3542:  // 七つの大罪
            return 4153;
        case 3506:  // グリザイアの果実
            return 4196;
        case 3545:  // 結城友奈は勇者である
            return 4162;
        case 3510:  // 大図書館の羊飼い
            return 4202;
        case 3725:  // 翠星のガルガンティア ～めぐる航路、遥か～
            return 4103;
        case 3532:  // 異能バトルは日常系のなかで
            return 4142;
        case 3500:  // Fate/stay night [Unlimited Blade Works]
            return 4177;
        case 3501:  // 甘城ブリリアントパーク
            return 4170;
        case 3504:  // 棺姫のチャイカ AVENGING BATTLE
            return 4158;
        case 3539:  // クロスアンジュ 天使と竜の輪舞
            return 4180;
        case 3526:  // ガンダムビルドファイターズトライ
            return 4200;
        case 3515:  // 暁のヨナ
            return 4126;
        case 3522:  // 失われた未来を求めて
            return 4154;
        case 3521:  // トリニティセブン
            return 4141;
        case 4074:  // ストライクウィッチーズ Operation Victory Arrow
            return 4131;
        case 3528:  // トライブクルクル
            return 4190;
        case 3533:  // カリメロ(2014)
            return 4204;
        case 3507:  // 繰繰れ！コックリさん
            return 4198;
        case 3581:  // 憑物語
            return 4246;
        case 3537:  // 旦那が何を言っているかわからない件
            return 4206;
        case 3541:  // まじっく快斗1412
            return 4194;
        case 3604:  // 宇宙戦艦ヤマト2199 追憶の航海
            return 4212;
        case 3627:  // テイルズ オブ ゼスティリア ～導師の夜明け～
            return 4239;
        case 3547:  // こんな私たちがなりゆきでヒロインになった結果www (なりヒロwww)
            return 4221;
        case 3628:  // この男子、石化に悩んでます。
            return 4296;
        case 3585:  // ポケットモンスター XY特別編 最強メガシンカ ～Act II～
            return 5123;
        case 3531:  // オオカミ少女と黒王子
            return 4172;
        case 3529:  // 山賊の娘ローニャ
            return 4203;
        case 4526:  // 楽園追放 -Expelled From Paradise-
            return 4211;
        case 3548:  // ガンダム Gのレコンギスタ
            return 4192;
        case 3674:  // ゆるゆり なちゅやちゅみ！
            return 4363;
        case 3926:  // 映画ハピネスチャージプリキュア！ 人形の国のバレリーナ
            return 4510;
        case 4275:  // 劇場版 アイカツ！
            return 4165;
        case 3536:  // 愛・天地無用！
            return 4156;
        case 3516:  // selector spread WIXOSS
            return 4193;
        case 3535:  // バディ・コンプレックス 完結編-あの空に還る未来で-
            return 4191;
        case 3573:  // カードファイト!! ヴァンガードG
            return 5941;

        // 2014年冬
        case 3262:  // 妖怪ウォッチ
            return 2325;
        case 3257:  // ロボットガールズZ
            return 2447;
        case 3247:  // 桜Trick
            return 848;
        case 3291:  // 犬猫アワー 47都道府犬R＆にゃ～めん
            return 4024;
        case 3292:  // てさぐれ！部活もの あんこーる
            return 4025;
        case 3259:  // 中二病でも恋がしたい！戀
            return 1277;
        case 3286:  // みんな集まれ！ファルコム学園
            return 2145;
        case 3260:  // 世界征服～謀略のズヴィズダー～
            return 1097;
        case 3665:  // 夏目友人帳 いつかゆきのひに
            return 3929;
        case 3225:  // 未確認で進行形
            return 2167;
        case 3246:  // 魔法戦争
            return 2116;
        case 3366:  // パロルのみらい島
            return 6051;
        case 3310:  // ニャンだ？フルチャンネル
            return 4009;
        case 4001:  // THE IDOLM@STER MOVIE 輝きの向こう側へ！
            return 4113;
        case 4490:  // アナと雪の女王
            return 8079;
        case 3238:  // 咲-Saki- 全国編
            return 835;
        case 3266:  // 鬼灯の冷徹
            return 2015;
        case 3283:  // お姉ちゃんが来た
            return 326;
        case 3245:  // ディーふらぐ！
            return 1350;
        case 3279:  // うーさーのその日暮らし 覚醒編
            return 4023;
        case 3276:  // GO！GO！575
            return 716;
        case 3236:  // ウィザード・バリスターズ～弁魔士セシル
            return 208;
        case 3248:  // のうりん
            return 1561;
        case 3288:  // 地下すぎアイドル あかえちゃん
            return 4008;
        case 3254:  // いなり、こんこん、恋いろは。
            return 138;
        case 3244:  // となりの関くん
            return 1430;
        case 3367:  // 大きい1年生と小さな2年生
            return 5736;
        case 3252:  // ニセコイ
            return 1528;
        case 3227:  // 絶滅危愚少女 Amazing Twins
            return 2801;
        case 3267:  // ハマトラ THE ANIMATION
            return 1636;
        case 3239:  // 生徒会役員共＊
            return 1128;
        case 3243:  // バディ・コンプレックス
            return 1658;
        case 3240:  // ウィッチクラフトワークス
            return 209;
        case 3256:  // 最近、妹のようすがちょっとおかしいんだが。
            return 845;
        case 3278:  // ストレンジ・プラス
            return 1034;
        case 3241:  // スペース☆ダンディ
            return 1039;
        case 3264:  // Z/X IGNITION
            return 1072;
        case 3258:  // そにアニ -SUPER SONICO THE ANIMATION-
            return 1156;
        case 3242:  // ノラガミ
            return 4026;
        case 3284:  // めいたんていラスカル
            return 4010;
        case 3235:  // とある飛空士への恋歌
            return 1421;
        case 3261:  // ノブナガン
            return 1572;
        case 3265:  // ノブナガ・ザ・フール
            return 1573;
        case 3275:  // ハピネスチャージプリキュア！
            return 1635;
        case 3272:  // pupa
            return 1756;
        case 3234:  // Wake Up, Girls！
            return 183;
        case 3290:  // 攻殻機動隊入門あらいず
            return 4022;
        case 3271:  // フューチャーカード バディファイト
            return 1899;
        case 3263:  // プピポー！
            return 1915;
        case 3249:  // マケン姫っ！通
            return 2051;
        case 4513:  // モーレツ宇宙海賊 ABYSS OF HYPERSPACE -亜空の深淵-
            return 4073;

        // 2015年春
        case 3713:  // シドニアの騎士 第九惑星戦役
            return 4282;
        case 3896:  // 聖闘士星矢 黄金魂 -soul of gold-
            return 4358;
        case 3702:  // ベイビーステップ 第2シリーズ
            return 4350;
        case 3718:  // 高宮なすのです！
            return 4359;
        case 3728:  // アルスラーン戦記 (2015)
            return 4254;
        case 3701:  // Fate/stay night [Unlimited Blade Works] 2ndシーズン
            return 4361;
        case 3681:  // トランスフォーマーアドベンチャー
            return 4343;
        case 3729:  // 秘密結社 鷹の爪 DO
            return 4390;
        case 3709:  // アルティメット・スパイダーマン ウェブ・ウォーリアーズ
            return 4393;
        case 3696:  // 魔法少女リリカルなのはViVid
            return 4159;
        case 3687:  // 響け！ユーフォニアム
            return 4308;
        case 3716:  // 攻殻機動隊ARISE ALTERNATIVE ARCHITECTURE
            return 4351;
        case 3715:  // うたの☆プリンスさまっ♪ マジLOVEレボリューションズ
            return 4355;
        case 3680:  // パンチライン
            return 4283;
        case 3700:  // トリアージX
            return 4218;
        case 3690:  // ハイスクールD×D BorN
            return 4360;
        case 3686:  // グリザイアの楽園
            return 4357;
        case 3698:  // やはり俺の青春ラブコメはまちがっている。続
            return 4244;
        case 3699:  // 食戟のソーマ
            return 4253;
        case 3747:  // 銀魂゜
            return 4352;
        case 3689:  // えとたま
            return 4276;
        case 3720:  // 血界戦線
            return 4252;
        case 3730:  // 俺物語!!
            return 4275;
        case 3672:  // ハロー!!きんいろモザイク
            return 4148;
        case 3739:  // たまごっち！たまともだいしゅーGO
            return 4401;
        case 3694:  // 境界のRINNE
            return 4277;
        case 3736:  // ニンジャスレイヤー フロムアニメイシヨン
            return 4125;
        case 3717:  // てーきゅう 第4期
            return 4217;
        case 3695:  // ダンジョンに出会いを求めるのは間違っているだろうか
            return 4247;
        case 3684:  // ニセコイ：
            return 4230;
        case 3769:  // ダイヤのA ‐SECOND SEASON‐
            return 4405;
        case 4073:  // ラブライブ！The School Idol Movie
            return 4438;
        case 3712:  // 電波教師
            return 4347;
        case 3722:  // 旦那が何を言っているかわからない件 2スレ目
            return 4345;
        case 3703:  // 山田くんと7人の魔女
            return 4288;
        case 3691:  // 終わりのセラフ
            return 4234;
        case 3927:  // 百日紅～Miss HOKUSAI～
            return 7666;
        case 3679:  // プラスティック・メモリーズ
            return 4251;
        case 3721:  // おまかせ！みらくるキャット団
            return 4391;
        case 3704:  // バトルスピリッツ烈火魂
            return 4344;
        case 4093:  // 劇場版 境界の彼方 -I'LL BE HERE-
            return 4242;
        case 3673:  // 長門有希ちゃんの消失
            return 4333;
        case 3688:  // SHOW BY ROCK!!
            return 4287;
        case 3697:  // レーカン！
            return 4291;
        case 3685:  // グリザイアの迷宮
            return 4356;
        case 3731:  // ジュエルペット マジカルチェンジ
            return 4397;
        case 3732:  // ゴー！ゴー！キッチン戦隊クックルン
            return 4399;
        case 3714:  // 放課後のプレアデス (2015)
            return 4362;
        case 3738:  // GON -ゴン-(第2期)
            return 4400;
        case 3776:  // わしも-wasimo-(第3シリーズ)
            return 4406;
        case 4267:  // 台風のノルダ
            return 4414;
        case 4182:  // 名探偵コナン 業火の向日葵
            return 4722;
        case 3719:  // ガンスリンガー ストラトス
            return 4298;
        case 3723:  // 浦和の調ちゃん
            return 4354;
        case 3778:  // 怪盗ジョーカー シーズン2
            return 4437;
        case 4359:  // アベンジャーズ・アッセンブル
            return 4979;
        case 3876:  // たまゆら～卒業写真～
            return 4181;
        case 3711:  // ミカグラ学園組曲
            return 4299;
        case 3710:  // にゅるにゅる!!KAKUSENくん (第2期)
            return 4338;
        case 3743:  // VAMPIRE HOLMES (ヴァンパイアホームズ)
            return 4346;
        case 3678:  // てさぐれ！部活もの すぴんおふ プルプルんシャルムと遊ぼう
            return 4348;
        case 3706:  // 英国一家、日本を食べる
            return 4353;
        case 3692:  // アドベンチャー・タイム
            return 4394;
        case 3740:  // レゴ ニンジャゴー
            return 4402;
        case 3742:  // 雨色ココア
            return 4403;
        case 3748:  // フューチャーカード バディファイト100
            return 4404;
        case 4092:  // クレヨンしんちゃん オラの引越し物語 サボテン大襲撃
            return 6032;
        case 4416:  // 弱虫ペダル Re:ROAD
            return 5091;
        case 3789:  // ロボットガールズZ プラス
            return 4307;
        case 3726:  // デュエル・マスターズVSR
            return 4349;
        case 3707:  // ツムツム
            return 4365;
        case 4802:  // 七つの大罪 -外伝- バンデット・バン
            return 5646;

        // 2015年夏
        case 3831:  // オーバーロード
            return 4440;
        case 3808:  // ケイオスドラゴン 赤竜戦役
            return 4336;
        case 3811:  // キュートランスフォーマー さらなる人気者への道
            return 4439;
        case 3798:  // 城下町のダンデライオン
            return 4419;
        case 3830:  // ドラゴンボール超
            return 4431;
        case 3809:  // 戦姫絶唱シンフォギアGX
            return 4374;
        case 3819:  // 赤髪の白雪姫
            return 4341;
        case 3802:  // 下ネタという概念が存在しない退屈な世界
            return 4388;
        case 3839:  // ヘタリア The World Twinkle (第6期)
            return 4436;
        case 3792:  // のんのんびより りぴーと
            return 4309;
        case 3833:  // ガッチャマンクラウズ インサイト
            return 4313;
        case 3810:  // GOD EATER (ゴッドイーター)
            return 4228;
        case 3826:  // 空戦魔導士候補生の教官
            return 4379;
        case 3835:  // Fate/kaleid liner プリズマ☆イリヤ ツヴァイ ヘルツ！
            return 4210;
        case 3832:  // アイドルマスター シンデレラガールズ 2nd SEASON
            return 4430;
        case 3801:  // 実は私は
            return 4387;
        case 3812:  // てーきゅう 第5期
            return 4426;
        case 3794:  // だんちがい
            return 4429;
        case 3827:  // 純情ロマンチカ3
            return 4378;
        case 3849:  // ビキニ・ウォリアーズ
            return 4428;
        case 3828:  // 監獄学園
            return 4375;
        case 3815:  // GANGSTA.
            return 4433;
        case 3850:  // VENUS PROJECT -CLIMAX-
            return 4424;
        case 3825:  // それが声優！
            return 4310;
        case 3807:  // 青春×機関銃
            return 4418;
        case 3795:  // 干物妹！うまるちゃん
            return 4303;
        case 3813:  // ワカコ酒
            return 4425;
        case 3803:  // GATE 自衛隊 彼の地にて、斯く戦えり
            return 4304;
        case 3796:  // To LOVEる -とらぶる- ダークネス2nd
            return 4305;
        case 3818:  // モンスター娘のいる日常
            return 4372;
        case 3821:  // Charlotte
            return 4306;
        case 3805:  // がっこうぐらし！
            return 4340;
        case 3817:  // 六花の勇者
            return 4385;
        case 3816:  // うしおととら (TVシリーズ)
            return 4328;
        case 4758:  // ARIA The AVVENIRE
            return 4321;
        case 3845:  // ミリオンドール
            return 4332;
        case 3823:  // うーさーのその日暮らし 夢幻編
            return 4371;
        case 5195:  // 劇場版 デート・ア・ライブ 万由里ジャッジメント
            return 4376;
        case 3797:  // WORKING!!!
            return 4423;
        case 3799:  // デュラララ!!×2 転
            return 4422;
        case 3822:  // ミス・モノクローム -The Animation- 2
            return 4420;
        case 3877:  // ONE PIECE エピソードオブサボ 〜3兄弟の絆 奇跡の再会と受け継がれる意志〜
            return 7138;
        case 3806:  // アクエリオンロゴス
            return 4435;
        case 3880:  // ナルどマ
            return 4475;
        case 3824:  // 怪獣酒場 カンパーイ！
            return 4427;
        case 4451:  // BORUTO -NARUTO THE MOVIE-
            return 4921;
        case 3862:  // バケモノの子
            return 4301;
        case 4268:  // ポケモン・ザ・ムービーXY 光輪の超魔神 フーパ
            return 5003;
        case 3800:  // Classroom☆Crisis
            return 4386;
        case 3829:  // 乱歩奇譚 Game of Laplace
            return 4417;
        case 3820:  // わかば＊ガール
            return 4421;
        case 3837:  // 洲崎西 THE ANIMATION
            return 4434;
        case 3865:  // ゆるゆり なちゅやちゅみ！＋
            return 4442;
        case 3866:  // 暗闇三太
            return 4443;
        case 4664:  // 心が叫びたがってるんだ。
            return 4290;
        case 3781:  // ピカイア！
            return 4382;
        case 3793:  // おくさまが生徒会長！
            return 4416;
        case 3852:  // 枕男子
            return 4432;
        case 4387:  // 劇場版 弱虫ペダル
            return 5092;

        // 2015年秋
        case 3903:  // ミス・モノクローム -The Animation- 3
            return 4492;
        case 5860:  // 映画 ハイ☆スピード！－Free! Starting Days－
            return 4573;
        case 3907:  // コメット・ルシファー
            return 4453;
        case 3935:  // Dance with Devils
            return 4330;
        case 3933:  // すべてがFになる THE PERFECT INSIDER
            return 4289;
        case 3893:  // ご注文はうさぎですか？？
            return 4452;
        case 3929:  // 金田一少年の事件簿R (第2シリーズ)
            return 4478;
        case 3912:  // 対魔導学園35試験小隊
            return 4466;
        case 3944:  // 不思議なソメラちゃん
            return 4474;
        case 3908:  // ふうせんいぬティニー (第2シリーズ)
            return 4494;
        case 3919:  // 蒼穹のファフナーEXODUS (第2クール)
            return 4456;
        case 3992:  // ミニはま -MINIMUM HAMATORA-
            return 4527;
        case 3890:  // 落第騎士の英雄譚
            return 4460;
        case 4013:  // 悪魔バスター★スター・バタフライ
            return 4597;
        case 3917:  // ノラガミ ARAGOTO
            return 4464;
        case 3902:  // ルパン三世 (2015)
            return 4240;
        case 3943:  // JKめし！
            return 4503;
        case 3911:  // 櫻子さんの足下には死体が埋まっている
            return 4342;
        case 3915:  // ワンパンマン
            return 4370;
        case 3901:  // 温泉幼精ハコネちゃん
            return 4450;
        case 3921:  // コンクリート・レボルティオ～超人幻想～
            return 4455;
        case 3888:  // ランス・アンド・マスクス
            return 4235;
        case 4403:  // 映画 妖怪ウォッチ エンマ大王と5つの物語だニャン！
            return 4588;
        case 3946:  // 小森さんは断れない！
            return 4454;
        case 3950:  // ブレイブビーツ
            return 4505;
        case 3882:  // ヘヴィーオブジェクト
            return 4462;
        case 3970:  // あにトレ！EX
            return 4473;
        case 3889:  // ヤング ブラック・ジャック
            return 4461;
        case 3913:  // おそ松さん
            return 4447;
        case 3941:  // てーきゅう 第6期
            return 4488;
        case 3920:  // ハイキュー!! セカンドシーズン
            return 4471;
        case 3900:  // 学戦都市アスタリスク
            return 4451;
        case 3928:  // PEANUTS スヌーピー -ショートアニメ-
            return 4500;
        case 3940:  // ザ・ペンギンズ from マダガスカル シーズン3
            return 4504;
        case 3922:  // 終わりのセラフ 名古屋決戦編
            return 4448;
        case 3885:  // 進撃！巨人中学校
            return 4467;
        case 3883:  // 緋弾のアリアAA
            return 4463;
        case 4470:  // ハーモニー
            return 4302;
        case 3952:  // おしりかじり虫 (第4シリーズ) 
            return 4507;
        case 3957:  // Peeping Life TV シーズン1 ??
            return 4509;
        case 3918:  // K RETURN OF KINGS
            return 4331;
        case 3886:  // 俺がお嬢様学校に「庶民サンプル」としてゲッツされた件
            return 4326;
        case 3881:  // ハッカドール THE あにめ～しょん
            return 4468;
        case 3985:  // ポケットモンスター XY&Z
            return 4519;
        case 3979:  // どうしても干支にはいりたい
            return 4516;
        case 3884:  // ゆるゆり さん☆ハイ！
            return 4369;
        case 3956:  // 猫なんかよんでもこない。
            return 4508;
        case 3892:  // かみさまみならい ヒミツのここたま
            return 4476;
        case 3973:  // 血液型くん！3
            return 4512;
        case 4024:  // 機動戦士ガンダム サンダーボルト
            return 4578;
        case 4015:  // ONE PIECE 〜アドベンチャー オブ ネブランディア〜
            return 4596;
        case 3906:  // 劇場版 蒼き鋼のアルペジオ -アルス・ノヴァ- Cadenza
            return 4319;
        case 4449:  // リトルウィッチアカデミア 魔法仕掛けのパレード
            return 4334;
        case 3899:  // いとしのムーコ
            return 4486;
        case 3972:  // 今際の国のアリス
            return 4480;
        case 3986:  // カード・バトルZERO
            return 4520;
        case 4469:  // 屍者の帝国
            return 4285;
        case 3891:  // うたわれるもの 偽りの仮面
            return 4457;
        case 3932:  // 機動戦士ガンダム 鉄血のオルフェンズ
            return 4469;
        case 3959:  // 雨色ココア Rainy colorへようこそ！
            return 4470;
        case 3923:  // スタミュ 高校星歌劇
            return 4472;
        case 3894:  // 影鰐-KAGEWANI-
            return 4477;
        case 3958:  // 新あたしンち
            return 4479;
        case 3916:  // ヴァルキリードライヴ マーメイド
            return 4485;
        case 3966:  // カードファイト!! ヴァンガードG ギアースクライシス編
            return 4490;
        case 3897:  // トランスフォーマーアドベンチャー(第2期)
            return 4491;
        case 3910:  // 牙狼 -紅蓮ノ月-
            return 4496;
        case 3984:  // 姉ログ
            return 4513;
        case 3994:  // ノゾ×キミ
            return 4514;
        case 3999:  // ファンタジスタ ステラ
            return 4515;
        case 3887:  // 新妹魔王の契約者 BURST
            return 4381;
        case 3898:  // 終物語
            return 4449;
        case 3909:  // DIABOLIK LOVERS MORE,BLOOD
            return 4465;
        case 3914:  // DD北斗の拳2
            return 4481;
        case 3955:  // 探偵チームKZ事件ノート
            return 4483;
        case 3976:  // こわぼん
            return 4487;
        case 3934:  // カンフー・パンダ ザ・シリーズ
            return 4501;
        case 3942:  // どちゃもん じゅにあ
            return 4502;
        case 5233:  // GAMBA ガンバと仲間たち
            return 4525;

        // 2015年冬
        case 3669:  // アニメで分かる心療内科
            return 4241;
        case 3596:  // DOG DAYS″
            return 4160;
        case 3607:  // 一騎当千 Extravaganza Epoch
            return 4258;
        case 3620:  // ローリング☆ガールズ
            return 4268;
        case 3597:  // ユリ熊嵐
            return 4188;
        case 3636:  // 黒子のバスケ 第3期
            return 4269;
        case 3624:  // 夜ノヤッターマン
            return 4273;
        case 3625:  // デュラララ!!×2 承
            return 4166;
        case 3610:  // 幸腹グラフィティ
            return 4146;
        case 3600:  // 純潔のマリア
            return 4219;
        case 3608:  // 艦隊これくしょん -艦これ-
            return 4179;
        case 3599:  // 聖剣使いの禁呪詠唱
            return 4227;
        case 3693:  // ポケットモンスター XY特別編 最強メガシンカ ～Act III～
            return 4364;
        case 3609:  // 東京喰種トーキョーグール√A
            return 4229;
        case 3601:  // 新妹魔王の契約者
            return 4173;
        case 3613:  // ISUCA
            return 4215;
        case 3629:  // ジョジョの奇妙な冒険 スターダストクルセイダース エジプト編
            return 4271;
        case 3595:  // 冴えない彼女の育てかた
            return 4266;
        case 3614:  // 神様はじめました◎
            return 4183;
        case 3644:  // Go！プリンセスプリキュア
            return 4274;
        case 3633:  // デス・パレード
            return 4280;
        case 3616:  // 少年ハリウッド -HOLLY STAGE FOR 50-
            return 4233;
        case 3618:  // アルドノア・ゼロ (第2期)
            return 4292;
        case 3623:  // みんな集まれ！ファルコム学園SC
            return 4261;
        case 3630:  // ドアマイガーD
            return 4262;
        case 3611:  // 銃皇無尽のファフニール
            return 4267;
        case 3593:  // アブソリュート・デュオ
            return 4147;
        case 3631:  // 暗殺教室
            return 4145;
        case 3602:  // 美男高校地球防衛部LOVE！
            return 4232;
        case 5217:  // 劇場版 PSYCHO-PASS サイコパス
            return 4224;
        case 3621:  // 戦国無双
            return 4255;
        case 3619:  // 探偵歌劇ミルキィホームズTD
            return 4260;
        case 3779:  // 百花繚乱 サムライアフター
            return 4412;
        case 3588:  // アイドルマスター シンデレラガールズ
            return 4256;
        case 3615:  // 蒼穹のファフナー EXODUS
            return 4151;
        case 3650:  // 血液型くん！2
            return 4249;
        case 4183:  // 新トムとジェリー ショー
            return 7520;
        case 3895:  // 劇場版 蒼き鋼のアルペジオ -アルス・ノヴァ- DC
            return 4318;
        case 3626:  // キュートランスフォーマー 帰ってきたコンボイの謎
            return 4263;
        case 3622:  // みりたり！
            return 4264;
        case 3603:  // ぱんきす！2次元
            return 4265;
        case 3969:  // スター・ウォーズ 反乱者たち
            return 4270;
        case 4082:  // ドラえもん のび太の宇宙英雄記
            return 6034;
        case 3632:  // わしも-wasimo- (第2シリーズ)
            return 4294;
        case 3682:  // 映画 プリキュアオールスターズ 春のカーニバル♪
            return 6017;

        // 2016年春
        case 4147:  // 薄桜鬼～御伽草子～
            return 4693;
        case 4101:  // 宇宙パトロールルル子
            return 4648;
        case 4083:  // 三者三葉
            return 4672;
        case 4149:  // ラグナストライクエンジェルズ
            return 4794;
        case 4112:  // アルティメット・スパイダーマン VS シニスター・シックス
            return 4683;
        case 5926:  // ずっと前から好きでした。～告白実行委員会～
            return 4818;
        case 4122:  // フューチャーカード バディファイトDDD
            return 4696;
        case 4146:  // 12歳。～ちっちゃなムネのトキメキ～
            return 4675;
        case 4091:  // 聖戦ケルベロス 竜刻のファタリテ
            return 4625;
        case 4100:  // ジョジョの奇妙な冒険 ダイヤモンドは砕けない
            return 4689;
        case 4125:  // 境界のRINNE（第2シリーズ）
            return 4687;
        case 4134:  // 影鰐-KAGEWANI- 承
            return 4685;
        case 4167:  // 少年アシベ GO!GO!ゴマちゃん
            return 4688;
        case 4136:  // 美少女戦士セーラームーンCrystal Season III
            return 4695;
        case 4174:  // 怪盗ジョーカー シーズン3
            return 4684;
        case 4132:  // デュエル・マスターズVSRF
            return 4795;
        case 4087:  // アイカツスターズ！
            return 4646;
        case 5389:  // ヒックとドラゴン：新たな世界へ！
            return 8218;
        case 4123:  // レゴ ニンジャゴー (天空の海賊編)
            return 4780;
        case 4127:  // エンドライド
            return 4617;
        case 4135:  // ジョーカー・ゲーム
            return 4673;
        case 4160:  // 双星の陰陽師
            return 4677;
        case 4098:  // 学戦都市アスタリスク 2nd SEASON
            return 4666;
        case 4094:  // ふらいんぐうぃっち
            return 4681;
        case 4152:  // ぼのぼの (2016)
            return 4704;
        case 4179:  // あはれ！名作くん
            return 4811;
        case 4097:  // キズナイーバー
            return 4668;
        case 4150:  // 美少女遊戯ユニット クレーンゲール
            return 4796;
        case 4103:  // 迷家-マヨイガ-
            return 4634;
        case 4131:  // とんかつDJアゲ太郎
            return 4691;
        case 4095:  // ハイスクール・フリート
            return 4619;
        case 4169:  // バトルスピリッツ ダブルドライブ
            return 4694;
        case 4108:  // 坂本ですが？
            return 4620;
        case 4086:  // ネトゲの嫁は女の子じゃないと思った？
            return 4658;
        case 4157:  // 鬼斬
            return 4637;
        case 4119:  // 文豪ストレイドッグス
            return 4564;
        case 4117:  // 甲鉄城のカバネリ
            return 4286;
        case 4109:  // マクロスΔ（デルタ）
            return 4245;
        case 4099:  // 田中くんはいつもけだるげ
            return 4678;
        case 4133:  // 僕のヒーローアカデミア
            return 4616;
        case 4173:  // ねこねこ日本史
            return 4707;
        case 4574:  // 名探偵コナン 純黒の悪夢
            return 4814;
        case 4110:  // クロムクロ
            return 4643;
        case 4187:  // カミワザ・ワンダ
            return 4667;
        case 4115:  // うしおととら (TVシリーズ・第3クール)
            return 4777;
        case 4114:  // Re:ゼロから始める異世界生活
            return 4636;
        case 4124:  // 逆転裁判 〜その「真実」、異議あり！〜
            return 4669;
        case 4104:  // くまみこ
            return 4670;
        case 4126:  // コンクリート・レボルティオ～超人幻想～ THE LAST SONG
            return 4671;
        case 4107:  // 少年メイド
            return 4674;
        case 4120:  // SUPER LOVERS (スーパーラヴァーズ)
            return 4676;
        case 4128:  // TERRAFORMARS REVENGE (テラフォーマーズ リベンジ)
            return 4690;
        case 4185:  // カードファイト!! ヴァンガードG ストライドゲート編
            return 4708;
        case 4116:  // ニンジャスレイヤー フロムアニメイシヨン（スペシャル・エディシヨン版）
            return 4778;
        case 4177:  // ぼくらベアベアーズ
            return 4810;
        case 4203:  // ほのぼのログ
            return 4843;
        case 4105:  // ばくおん!!
            return 4622;
        case 4106:  // パンでPeace!
            return 4663;
        case 4096:  // あんハピ♪
            return 4664;
        case 4085:  // ハンドレッド
            return 4679;
        case 4151:  // ワガママハイスペック
            return 4682;
        case 4191:  // パワーパフ ガールズ (2016)
            return 4827;
        case 4192:  // ぱんどせる
            return 4828;
        case 4113:  // うさかめ
            return 4665;
        case 4130:  // 機動戦士ガンダムUC（ユニコーン） RE:0096
            return 4686;
        case 4121:  // ビッグオーダー
            return 4680;
        case 4168:  // ベイブレードバースト
            return 4697;
        case 4111:  // マギ シンドバッドの冒険
            return 4698;
        case 4155:  // わしも-wasimo-(第4シリーズ)
            return 4797;
        case 4693:  // 劇場版 響け！ユーフォニアム～北宇治高校吹奏楽部へようこそ～
            return 4819;
        case 4202:  // レゴ ネックスナイツ
            return 4852;
        case 4221:  // RS計画 -Rebirth Storage-
            return 4865;

        // 2016年夏
        case 4569:  // planetarian～星の人～
            return 4833;
        case 4292:  // こちら葛飾区亀有公園前派出所～THE FINAL 両津勘吉最後の日～
            return 4956;
        case 4253:  // SERVAMP -サーヴァンプ-
            return 4766;
        case 4248:  // パズドラクロス
            return 4767;
        case 4207:  // この美術部には問題がある！
            return 4618;
        case 4265:  // トランスフォーマーアドベンチャー -マイクロンの章-
            return 4869;
        case 4208:  // あまんちゅ！
            return 4765;
        case 4262:  // ダンガンロンパ３ –The End of 希望ヶ峰学園– 絶望編
            return 4831;
        case 4232:  // ツキウタ。THE ANIMATION
            return 4816;
        case 4236:  // チア男子!!
            return 4787;
        case 4237:  // B-PROJECT～鼓動＊アンビシャス～
            return 4803;
        case 4251:  // SHOW BY ROCK!! しょ～と!!
            return 4615;
        case 4257:  // OZMAFIA!! (オズマフィア)
            return 4805;
        case 4240:  // アクティヴレイド -機動強襲室第八係-  2nd
            return 4764;
        case 4277:  // 七つの大罪 聖戦の予兆
            return 4802;
        case 4244:  // ベルセルク (2016年)
            return 4635;
        case 4212:  // クオリディア・コード
            return 4804;
        case 4210:  // TABOO TATTOO (タブー・タトゥー)
            return 4785;
        case 4227:  // 不機嫌なモノノケ庵
            return 4770;
        case 4242:  // モブサイコ100
            return 4791;
        case 4230:  // 91Days
            return 4793;
        case 4263:  // バッテリー
            return 4734;
        case 4239:  // DAYS
            return 4822;
        case 4216:  // Fate/kaleid liner プリズマ☆イリヤ ドライ!!
            return 4790;
        case 4243:  // ぐらＰ＆ろで夫
            return 4856;
        case 4245:  // 初恋モンスター
            return 4662;
        case 4261:  // ダンガンロンパ3 –The End of 希望ヶ峰学園– 未来編
            return 4786;
        case 4222:  // Thunderbolt Fantasy 東離劍遊紀
            return 4859;
        case 4424:  // アクセル・ワールド INFINITE∞BURST
            return 4839;
        case 4276:  // 君の名は。
            return 4840;
        case 4225:  // Rewrite (リライト)
            return 4497;
        case 4206:  // はんだくん
            return 4769;
        case 4223:  // NEW GAME!
            return 4624;
        case 4215:  // 食戟のソーマ 弍ノ皿
            return 4650;
        case 4246:  // 斉木楠雄のΨ難
            return 4844;
        case 4279:  // PERSONA5 the Animation -THE DAY BREAKERS-
            return 4861;
        case 4199:  // ラブライブ！サンシャイン!!
            return 4772;
        case 4260:  // planetarian～ちいさなほしのゆめ～
            return 4832;
        case 4224:  // 腐男子高校生活
            return 4824;
        case 4214:  // アンジュ・ヴィエルジュ
            return 4626;
        case 4226:  // 甘々と稲妻
            return 4700;
        case 4211:  // レガリア The Three Sacred Stars
            return 4763;
        case 4235:  // アルスラーン戦記 風塵乱舞
            return 4801;
        case 4231:  // スカーレッドライダーゼクス
            return 4815;
        case 4254:  // タイムトラベル少女～マリ・ワカと8人の科学者たち～
            return 4846;
        case 4655:  // ポケモン・ザ・ムービーXY&Z ボルケニオンと機巧のマギアナ
            return 4870;
        case 4229:  // orange
            return 4645;
        case 4209:  // 魔装学園H×H (ハイブリッドハート)
            return 4771;
        case 4249:  // ばなにゃ
            return 4768;
        case 4241:  // テイルズ オブ ゼスティリア ザ クロス
            return 4788;
        case 4250:  // ねじ巻き精霊戦記 天鏡のアルデラミン
            return 4710;
        case 4213:  // D.Gray-man HALLOW
            return 4789;
        case 4218:  // ReLIFE
            return 4792;
        case 4233:  // 魔法少女？なりあ☆がーるず
            return 4851;
        case 4259:  // 美男高校地球防衛部LOVE！LOVE！
            return 4853;
        case 4252:  // 一人之下 the outcast
            return 4868;

        // 2016年秋
        case 4371:  // CHEATING CRAFT
            return 4953;
        case 4284:  // DRIFTERS
            return 4863;
        case 4375:  // 怪獣娘～ウルトラ怪獣擬人化計画～
            return 4838;
        case 4354:  // ルガーコード1951
            return 4660;
        case 4859:  // この世界の片隅に
            return 4325;
        case 4340:  // 3ねんDぐみガラスの仮面
            return 4952;
        case 4326:  // TRICKSTER -江戸川乱歩「少年探偵団」より-
            return 4849;
        case 4293:  // 刀剣乱舞-花丸-
            return 4809;
        case 4303:  // ガーリッシュ ナンバー
            return 4614;
        case 4310:  // タイガーマスクＷ
            return 4896;
        case 4307:  // クラシカロイド
            return 4806;
        case 4300:  // 夏目友人帳 伍
            return 4808;
        case 4329:  // こねこのチー ポンポンらー大冒険
            return 4834;
        case 4321:  // うどんの国の金色毛鞠
            return 4647;
        case 4324:  // アイドルメモリーズ
            return 4878;
        case 4357:  // きんだーてれび
            return 4978;
        case 4339:  // ペペペペン議員
            return 4975;
        case 4308:  // 装神少女まとい
            return 4886;
        case 4316:  // 灼熱の卓球娘
            return 4905;
        case 4408:  // がん がん がんこちゃん
            return 5088;
        case 4735:  // 殺せんせーＱ！
            return 5194;
        case 4332:  // 競女!!!!!!!!
            return 4895;
        case 4348:  // 雨色ココア in Hawaii
            return 4880;
        case 4341:  // 学園ハンサム
            return 4882;
        case 4313:  // バーナード嬢曰く。
            return 4936;
        case 4302:  // 私がモテてどうすんだ
            return 4760;
        case 4346:  // 侍霊演武：将星乱
            return 4976;
        case 4369:  // 猫のダヤン ふしぎ劇場
            return 4915;
        case 4344:  // 怪盗ジョーカー シーズン4
            return 4881;
        case 4317:  // 文豪ストレイドッグス (第2期)
            return 4774;
        case 4291:  // 終末のイゼッタ
            return 4875;
        case 4296:  // SHOW BY ROCK!!#
            return 4885;
        case 4389:  // ポケットモンスター サン&ムーン
            return 5002;
        case 4294:  // 魔法少女なんてもういいですから。セカンドシーズン
            return 4917;
        case 4388:  // トランスフォーマーアドベンチャー -マイクロンの章- 新たなる敵
            return 5051;
        case 4306:  // うたの☆プリンスさまっ♪ マジLOVEレジェンドスター
            return 4825;
        case 4298:  // 魔法少女育成計画
            return 4893;
        case 4295:  // 3月のライオン
            return 4773;
        case 4330:  // 亜人(第2期)
            return 4879;
        case 4319:  // 舟を編む
            return 4762;
        case 4377:  // 月曜日のたわわ
            return 4996;
        case 4283:  // 響け！ユーフォニアム2
            return 4826;
        case 4288:  // Occultic;Nine-オカルティック・ナイン-
            return 4920;
        case 4402:  // Fate/Grand Order –First Order–
            return 5048;
        case 4331:  // ナンバカ
            return 4835;
        case 4380:  // レゴ ニンジャゴー(よみがえりの日編) 
            return 5033;
        case 4336:  // モンスターハンターストーリーズ RIDE ON
            return 4894;
        case 4315:  // ハイキュー!! 烏野高校 VS 白鳥沢学園高校
            return 4836;
        case 4343:  // あおおに～じ・あにめーしょん～
            return 4908;
        case 4325:  // タイムボカン24
            return 4864;
        case 4286:  // ブレイブウィッチーズ
            return 4659;
        case 4318:  // ろんぐらいだぁす！
            return 4775;
        case 4301:  // てーきゅう 第8期
            return 4914;
        case 4345:  // 12歳。～ちっちゃなムネのトキメキ～ セカンドシーズン
            return 4884;
        case 5168:  // ポッピンQ
            return 4944;
        case 4352:  // ALL OUT!!オールアウト
            return 4644;
        case 4320:  // デジモンユニバース アプリモンスターズ
            return 4887;
        case 4299:  // ViVid Strike!
            return 4890;
        case 4297:  // にゃんぼー！
            return 4889;
        case 4290:  // ヘボット！
            return 4891;
        case 4322:  // マジきゅんっ！ルネッサンス
            return 4892;
        case 4355:  // カードファイト!! ヴァンガードG NEXT
            return 4910;
        case 4353:  // 戦国鳥獣戯画〜甲〜
            return 4912;
        case 4285:  // WWW.WORKING!!
            return 4951;
        case 5583:  // CYBORG009 CALL OF JUSTICE
            return 4967;
        case 4376:  // どちゃもん じゅにあ(第2シリーズ)
            return 4988;
        case 4323:  // ナゾトキネ
            return 4888;
        case 4305:  // ブブキ・ブランキ 星の巨人 
            return 4916;
        case 4397:  // レゴ ネックスナイツ (ナイツへの道編) 
            return 5059;
        case 4391:  // うさぎのモフィ(第4シーズン) 
            return 5060;
        case 4400:  // 名探偵コナン エピソード“ONE” 小さくなった名探偵
            return 5063;
        case 4797:  // イナズマデリバリー
            return 5764;
        case 4314:  // ステラのまほう
            return 4623;
        case 4281:  // おくさまが生徒会長!+!
            return 4854;
        case 4338:  // ドリフェス！
            return 4860;
        case 4311:  // 機動戦士ガンダム 鉄血のオルフェンズ (第2期)
            return 4883;
        case 4351:  // あにトレ!!XX～ひとつ屋根の下で～
            return 4904;
        case 5589:  // きんいろモザイク Pretty Days
            return 4932;
        case 4372:  // TO BE HERO
            return 4954;
        case 4358:  // Bloodivores
            return 4955;
        case 4809:  // 映画 妖怪ウォッチ 空飛ぶクジラとダブル世界の大冒険だニャン！
            return 6198;
        case 4327:  // フリップフラッパーズ
            return 4807;
        case 4287:  // Lostorage incited WIXOSS
            return 4837;
        case 4328:  // タマ＆フレンズ ～うちのタマ知りませんか？～
            return 4897;
        case 4337:  // 信長の忍び
            return 4898;
        case 4350:  // ユーリ!!! on ICE
            return 4899;
        case 4381:  // ガールフレンド（♪）
            return 4911;
        case 4356:  // ゼーガペイン ADP
            return 4933;
        case 4333:  // 奇異太郎少年の妖怪絵日記
            return 4935;
        case 4347:  // 美少女遊戯ユニット クレーンゲール ギャラクシー
            return 4937;
        case 4365:  // はがねオーケストラ
            return 4950;

        // 2016年冬
        case 4089:  // 映画プリキュアオールスターズ みんなで歌う♪奇跡の魔法！
            return 4705;
        case 4022:  // SUSHI POLICE
            return 4584;
        case 4058:  // 血液型くん！4
            return 4586;
        case 4039:  // 僕だけがいない街
            return 4565;
        case 4014:  // デュラララ!!×2 結
            return 4555;
        case 4023:  // ハルチカ ～ハルタとチカは青春する～
            return 4560;
        case 4075:  // 忍たま乱太郎の宇宙大冒険 with コズミックフロント☆NEXT
            return 4639;
        case 4062:  // がんばれ！ルルロロ(第3シリーズ)
            return 4611;
        case 4005:  // 蒼の彼方のフォーリズム
            return 4538;
        case 4050:  // 魔法少女なんてもういいですから。
            return 4566;
        case 4044:  // 亜人
            return 4541;
        case 4046:  // 大家さんは思春期！
            return 4543;
        case 4080:  // 彼女と彼女の猫 -Everything Flows-
            return 4652;
        case 4018:  // てーきゅう 第7期
            return 4580;
        case 4017:  // 無彩限のファントム・ワールド
            return 4567;
        case 4048:  // 暗殺教室 (第2期)
            return 4542;
        case 4008:  // GATE 自衛隊 彼の地にて、斯く戦えり（第2期）
            return 4546;
        case 4036:  // 赤髪の白雪姫 (第2期)
            return 4539;
        case 4045:  // 虹色デイズ
            return 4557;
        case 4041:  // 昭和元禄落語心中
            return 4314;
        case 4997:  // 暦物語
            return 4587;
        case 4012:  // ルパン三世 イタリアン・ゲーム
            return 4590;
        case 4042:  // ディバインゲート
            return 4553;
        case 4003:  // 最弱無敗の神装機竜
            return 4548;
        case 4038:  // アクティヴレイド -機動強襲室第八係-
            return 4540;
        case 4035:  // NORN9 ノルン+ノネット
            return 4558;
        case 4030:  // だがしかし
            return 4552;
        case 4011:  // おじさんとマシュマロ
            return 4545;
        case 4016:  // この素晴らしい世界に祝福を！
            return 4547;
        case 4234:  // ももくり
            return 4582;
        case 4064:  // 魔法つかいプリキュア！
            return 4583;
        case 4047:  // 石膏ボーイズ
            return 4551;
        case 4007:  // おしえて！ギャル子ちゃん
            return 4544;
        case 4009:  // シュヴァルツェスマーケン
            return 4549;
        case 4006:  // 少女たちは荒野を目指す
            return 4550;
        case 4040:  // Dimension W
            return 4554;
        case 4026:  // ブブキ・ブランキ
            return 4562;
        case 4029:  // ファンタシースターオンライン2 ジ アニメーション
            return 4561;
        case 4021:  // プリンス・オブ・ストライド　オルタナティブ
            return 4563;
        case 4025:  // 霊剣山 星屑たちの宴
            return 4571;
        case 4049:  // 闇芝居（3期）
            return 4570;
        case 4600:  // KING OF PRISM by PrettyRhythm
            return 4612;
        case 4489:  // 劇場版 selector destructed WIXOSS
            return 4633;
        case 4646:  // カラフル忍者いろまき
            return 4781;
        case 4037:  // ナースウィッチ小麦ちゃんR
            return 4556;
        case 4004:  // 灰と幻想のグリムガル
            return 4559;
        case 4028:  // 紅殻のパンドラ
            return 4577;
        case 4051:  // 旅街レイトショー
            return 4604;
        case 4027:  // ラクエンロジック
            return 4568;
        case 4072:  // この男子、魔法がお仕事です。
            return 4585;
        case 4071:  // リルリルフェアリル～妖精のドア～
            return 4613;

        // 2017年春
        case 4553:  // sin 七つの大罪
            return 5109;
        case 4496:  // アイドルマスター シンデレラガールズ劇場
            return 5193;
        case 4491:  // ダンジョンに出会いを求めるのは間違っているだろうか外伝 ソード・オラトリア
            return 5137;
        case 4498:  // ひなこのーと
            return 4981;
        case 4509:  // つぐもも
            return 5080;
        case 4492:  // サクラダリセット
            return 5077;
        case 4543:  // 僧侶と交わる色欲の夜に…
            return 5222;
        case 4488:  // 冴えない彼女の育てかた♭
            return 4725;
        case 4548:  // ラブ米 -WE LOVE RICE-
            return 5085;
        case 4512:  // サクラクエスト
            return 5062;
        case 4504:  // アリスと蔵六
            return 5157;
        case 4497:  // トミカハイパーレスキュー ドライブヘッド
            return 5170;
        case 4515:  // 僕のヒーローアカデミア (第2期)
            return 5083;
        case 4518:  // ツインエンジェルBREAK
            return 5043;
        case 4503:  // フレームアームズ・ガール
            return 5140;
        case 4521:  // 武装少女マキャヴェリズム
            return 5082;
        case 4528:  // Re:CREATORS (レクリエイターズ)
            return 5070;
        case 4501:  // ロクでなし魔術講師と禁忌教典
            return 5093;
        case 4551:  // 喧嘩番長 乙女-Girl Beats Boys-
            return 5076;
        case 4527:  // アバローのプリンセス エレナ
            return 5220;
        case 4564:  // あはれ！名作くん (第2期)
            return 5279;
        case 4541:  // アイドルタイムプリパラ
            return 5214;
        case 4573:  // 100%パスカル先生＆プリプリちぃちゃん!!
            return 5278;
        case 4506:  // エロマンガ先生
            return 4714;
        case 4538:  // ふるさとめぐり 日本の昔ばなし
            return 5224;
        case 4592:  // 遊☆戯☆王VRAINS
            return 5187;
        case 4545:  // 王室教師ハイネ
            return 5097;
        case 4542:  // 世界の闇図鑑
            return 5215;
        case 4546:  // BORUTO-ボルト- NARUTO NEXT GENERATIONS
            return 5084;
        case 4495:  // 進撃の巨人 Season 2
            return 4924;
        case 4516:  // 境界のRINNE（第3シリーズ）
            return 5041;
        case 5282:  // 夜は短し歩けよ乙女
            return 5162;
        case 4517:  // 夏目友人帳 陸
            return 5139;
        case 4514:  // 信長の忍び～伊勢・金ヶ崎篇～
            return 5184;
        case 4547:  // まけるな!!あくのぐんだん！
            return 5226;
        case 4558:  // アキンド星のリトル・ペソ
            return 5223;
        case 5026:  // 劇場版 魔法科高校の劣等生 星を呼ぶ少女
            return 4715;
        case 4510:  // ゼロから始める魔法の書
            return 4986;
        case 4507:  // 終末なにしてますか？ 忙しいですか？ 救ってもらっていいですか？
            return 5078;
        case 4549:  // ベルセルク (第2期)
            return 5044;
        case 4535:  // カブキブ！
            return 5073;
        case 4520:  // 正解するカド
            return 5136;
        case 4468:  // GRANBLUE FANTASY The Animation
            return 5102;
        case 4505:  // 恋愛暴君
            return 4627;
        case 4710:  // ワールドフールニュース PARTII
            return 7134;
        case 4523:  // 有頂天家族2
            return 5031;
        case 4500:  // クロックワーク・プラネット
            return 5099;
        case 4531:  // ID-0
            return 5168;
        case 4522:  // フューチャーカード バディファイトX
            return 5211;
        case 4555:  // ねこねこ日本史 (第2シリーズ)
            return 5217;
        case 4563:  // 兄に付ける薬はない！ -快把我哥帯走-
            return 5259;
        case 4572:  // 拡張少女系トライナリー
            return 4960;
        case 4529:  // 笑ゥせぇるすまん NEW
            return 5087;
        case 4550:  // 神撃のバハムート VIRGIN SOUL
            return 5115;
        case 4508:  // 月がきれい
            return 5138;
        case 4524:  // リルリルフェアリル～魔法の鏡～
            return 5180;
        case 4525:  // レゴ ニンジャゴー(時空の支配者編)
            return 5212;
        case 5269:  // 夜明け告げるルーのうた
            return 5228;
        case 4530:  // スタミュ (第2期)
            return 5042;
        case 4554:  // アトム ザ・ビギニング
            return 5072;
        case 4570:  // スナックワールド
            return 5079;
        case 4533:  // 覆面系ノイズ
            return 5081;
        case 4552:  // Room Mate ～One Room side M～
            return 5086;
        case 4544:  // 少年アシベ GO!GO!ゴマちゃん(第2シリーズ)
            return 5216;
        case 4557:  // 銀の墓守り
            return 5183;
        case 4539:  // ベイブレードバースト神
            return 5185;
        case 4537:  // デュエル・マスターズ (新シリーズ)
            return 5221;
        case 4540:  // わしも-wasimo-(第5シリーズ)
            return 5225;

        // 2017年夏
        case 4629:  // バチカン奇跡調査官
            return 5199;
        case 5901:  // 魔法少女リリカルなのは Reflection
            return 4983;
        case 4596:  // NEW GAME!!
            return 5227;
        case 4640:  // アクションヒロイン チアフルーツ
            return 5260;
        case 4637:  // 捏造トラップ-NTR-
            return 5285;
        case 4642:  // ひとりじめマイヒーロー
            return 5265;
        case 4634:  // スカートの中はケダモノでした。
            return 5331;
        case 4615:  // ひなろじ～from Luck & Logic～
            return 5143;
        case 4619:  // 最遊記RELOAD BLAST
            return 5160;
        case 4636:  // ナナマル サンバツ
            return 5182;
        case 4611:  // はじめてのギャル
            return 5198;
        case 4639:  // コンビニカレシ
            return 5262;
        case 4628:  // 魔法陣グルグル (2017年)
            return 5247;
        case 4654:  // 劇場版ポケットモンスター キミにきめた！
            return 5178;
        case 4620:  // 戦姫絶唱シンフォギアAXZ
            return 5245;
        case 5122:  // 交響詩篇エウレカセブン ハイエボリューション 1
            return 5436;
        case 4614:  // Fate/Apocrypha
            return 5101;
        case 5270:  // 打ち上げ花火、下から見るか？横から見るか？
            return 5163;
        case 4643:  // セントールの悩み
            return 5263;
        case 4652:  // THE REFLECTION –ザ・リフレクション–
            return 5243;
        case 4627:  // クリオネの灯り
            return 5283;
        case 4601:  // ナイツ＆マジック
            return 5197;
        case 5190:  // せいぜいがんばれ！魔法少女くるみ
            return 5589;
        case 4625:  // 妖怪アパートの幽雅な日常
            return 5248;
        case 4612:  // ようこそ実力至上主義の教室へ
            return 5322;
        case 4659:  // マーベル フューチャー・アベンジャーズ
            return 5352;
        case 5205:  // 劇場版 響け！ユーフォニアム～届けたいメロディ～
            return 5338;
        case 4603:  // 潔癖男子！青山くん
            return 5188;
        case 4598:  // 将国のアルタイル
            return 5100;
        case 4644:  // 異世界はスマートフォンとともに。
            return 5208;
        case 4645:  // カイトアンサ
            return 5240;
        case 4616:  // プリンセス・プリンシパル
            return 5246;
        case 4622:  // 天使の3P！
            return 5141;
        case 4623:  // 賭ケグルイ
            return 5167;
        case 4621:  // 地獄少女 宵伽
            return 5189;
        case 4626:  // 恋と嘘
            return 5195;
        case 4602:  // ボールルームへようこそ
            return 5114;
        case 4604:  // アホガール
            return 5158;
        case 4650:  // ノラと皇女と野良猫ハート
            return 5334;
        case 4617:  // メイドインアビス
            return 5121;
        case 4638:  // DIVE!!
            return 5161;
        case 4647:  // 縁結びの妖狐ちゃん
            return 5330;
        case 4633:  // 時間の支配者
            return 5244;
        case 4632:  // てーきゅう 第9期
            return 5264;
        case 4605:  // 徒然チルドレン
            return 5196;
        case 4613:  // ゲーマーズ！
            return 5242;
        case 4667:  // ユラユラすいぞくかん
            return 5492;
        case 5184:  // くまのがっこう パティシエ・ジャッキーとおひさまのスイーツ
            return 5767;
        case 5687:  // ガンダムビルドファイターズ バトローグ
            return 5414;
        case 4618:  // 活撃 刀剣乱舞
            return 5098;
        case 4597:  // バトルガール ハイスクール
            return 5142;
        case 4641:  // 18if
            return 5234;
        case 4606:  // RWBY Volume 1-3: The Beginning
            return 5249;
        case 4635:  // 闇芝居 (5期)
            return 5344;
        case 4610:  // 異世界食堂
            return 5261;
        case 4631:  // イケメン戦国◆時をかけるが恋は始まらない
            return 5335;
        case 4653:  // SHADOW OF LAFFANDOR ラファンドール国物語～FANTASY PICTURE STORY～
            return 5358;
        case 5027:  // メアリと魔女の花
            return 5169;
        case 5265:  // 劇場版 Fate/kaleid liner プリズマ☆イリヤ 雪下の誓い
            return 5192;
        case 4726:  // ドリフェス！R
            return 5445;
        case 4608:  // レゴ フレンズ
            return 5347;
        case 4624:  // 無責任ギャラクシー☆タイラー
            return 5348;
        case 4674:  // 女川中バスケ部 5人の夏
            return 5442;
        case 5900:  // 劇場版 生徒会役員共
            return 5463;
        case 4660:  // マーベル スパイダーマン
            return 5493;

        // 2017年秋
        case 4696:  // 宝石の国
            return 5337;
        case 4701:  // クジラの子らは砂上に歌う
            return 5250;
        case 4700:  // 鬼灯の冷徹 (第弐期)
            return 5270;
        case 4694:  // キノの旅 -the Beautiful World- the Animated Series
            return 5345;
        case 5081:  // ご注文はうさぎですか？？ ～Dear My Sister～
            return 5354;
        case 4679:  // Just Because!
            return 5359;
        case 4708:  // 血界戦線 & BEYOND
            return 5369;
        case 4684:  // 戦刻ナイトブラッド
            return 5370;
        case 4688:  // TSUKIPRO THE ANIMATION
            return 5378;
        case 4734:  // Wake Up, Girls！ 新章
            return 5380;
        case 4681:  // ネト充のススメ
            return 5405;
        case 4687:  // 十二大戦
            return 5417;
        case 4718:  // 食戟のソーマ 餐の皿
            return 5446;
        case 4677:  // アイドルマスター SideM
            return 5368;
        case 4717:  // ブラッククローバー
            return 5371;
        case 4685:  // お酒は夫婦になってから
            return 5411;
        case 4713:  // アニメガタリズ
            return 5267;
        case 4689:  // 少女終末旅行
            return 5418;
        case 4686:  // アイドルマスター シンデレラガールズ劇場 2nd SEASON
            return 5419;
        case 5859:  // 特別版 Free!-Take Your Marks-
            return 5614;
        case 4705:  // 干物妹！うまるちゃんR
            return 5255;
        case 4703:  // つうかあ
            return 5423;
        case 4719:  // URAHARA
            return 5363;
        case 4680:  // このはな綺譚
            return 5403;
        case 4745:  // Robomasters: The Animated Series
            return 5333;
        case 4695:  // 牙狼<GARO> -VANISHING LINE-
            return 5425;
        case 4682:  // 僕の彼女がマジメ過ぎるしょびっちな件
            return 5377;
        case 4721:  // いぬやしき
            return 5125;
        case 4722:  // 銀魂. ポロリ篇／銀ノ魂篇(前半戦)
            return 5364;
        case 4720:  // ピングー in ザ・シティ
            return 5479;
        case 4743:  // カードファイト!! ヴァンガードGZ
            return 5528;
        case 4690:  // お見合い相手は教え子、強気な、問題児。
            return 5440;
        case 4754:  // エスカクロン
            return 5537;
        case 4990:  // ヤマノススメ おもいでプレゼント
            return 5432;
        case 4709:  // 結城友奈は勇者である -鷲尾須美の章-/-勇者の章-
            return 5274;
        case 4744:  // PEANUTS スヌーピー-ショートアニメ-(2017)
            return 5526;
        case 4753:  // 猫のダヤン(シーズン4)
            return 5581;
        case 4702:  // ブレンド・S
            return 5336;
        case 4712:  // 3月のライオン (第2シリーズ)
            return 5206;
        case 4706:  // Infini-T Force
            return 5268;
        case 4697:  // 魔法使いの嫁
            return 5272;
        case 4757:  // いつだって僕らの恋は10センチだった。
            return 5468;
        case 4714:  // おそ松さん (第2期)
            return 5258;
        case 4727:  // Dies irae
            return 5360;
        case 4725:  // DYNAMIC CHORD
            return 5365;
        case 4692:  // ラブライブ！サンシャイン!! (第2期)
            return 5181;
        case 5087:  // 劇場版 はいからさんが通る 前編 ～紅緒、花の17歳～
            return 4847;
        case 4715:  // クラシカロイド (第2シリーズ)
            return 5269;
        case 4724:  // 王様ゲーム The Animation
            return 5402;
        case 4741:  // ラブ米 -WE LOVE RICE- 二期作
            return 5450;
        case 4729:  // GLAMOROUS HEROES
            return 5521;
        case 4723:  // ファイアボール ユーモラス
            return 5431;
        case 5182:  // 映画 かいけつゾロリ ZZのひみつ
            return 6694;
        case 5002:  // 焼肉店センゴク
            return 6118;
        case 4678:  // 妹さえいればいい。
            return 5277;
        case 5134:  // 映画 妖怪ウォッチ シャドウサイド 鬼王の復活
            return 6197;
        case 4742:  // レゴ ニンジャゴー(5)
            return 5527;
        case 4683:  // UQ HOLDER! ～魔法先生ネギま!2～
            return 5273;
        case 4704:  // Code:Realize ～創世の姫君～
            return 5284;
        case 4730:  // タイムボカン 逆襲の三悪人
            return 5448;
        case 4728:  // 大正ちっちゃいさん
            return 5449;
        case 4736:  // ディアホライゾン (被)
            return 5404;
        case 5119:  // 映画 キラキラ☆プリキュアアラモード パリッと！想い出のミルフィーユ！
            return 5582;
        case 4691:  // あめこん!! (雨色ココア第4期)
            return 5447;
        case 4739:  // EVIL OR LIVE
            return 5488;
        case 4707:  // aiseki MOGOL GIRL
            return 5491;
        case 4716:  // うっかりペネロペ 第4シリーズ
            return 5502;
        case 4746:  // おにゃんこポン
            return 5535;
        case 5499:  // バジャのスタジオ
            return 5576;
        case 4774:  // レゴ スター・ウォーズ フリーメーカーの冒険
            return 5645;

        // 2017年冬
        case 4431:  // 霊剣山 叡智への資格
            return 5045;
        case 4434:  // にゃんこデイズ
            return 5039;
        case 4396:  // スクールガールストライカーズ Animation Channel
            return 5037;
        case 4445:  // MARGINAL#4 KISSから創造るBig Bang
            return 4919;
        case 4482:  // 龍の歯医者
            return 4980;
        case 4401:  // この素晴らしい世界に祝福を！2
            return 4902;
        case 4412:  // 劇場版 ソードアート・オンライン -オーディナル・スケール-
            return 4709;
        case 4463:  // 戦隊ヒーロー スキヤキフォース
            return 5090;
        case 4428:  // 南鎌倉高校女子自転車部
            return 4994;
        case 4393:  // ガヴリールドロップアウト
            return 4998;
        case 4427:  // 風夏
            return 5049;
        case 4440:  // ハンドシェイカー
            return 4761;
        case 4436:  // アイドル事変
            return 4958;
        case 4442:  // ピアシェ～私のイタリアン～
            return 5040;
        case 4441:  // けものフレンズ
            return 5035;
        case 4446:  // SUPER LOVERS 2
            return 4862;
        case 4426:  // 幼女戦記
            return 5056;
        case 4430:  // 昭和元禄落語心中〜助六再び篇〜
            return 4918;
        case 4398:  // 弱虫ペダル NEW GENERATION
            return 4903;
        case 4429:  // 青の祓魔師 京都不浄王篇
            return 4982;
        case 4385:  // 政宗くんのリベンジ
            return 4993;
        case 4447:  // クズの本懐
            return 4726;
        case 4395:  // 亜人ちゃんは語りたい
            return 4947;
        case 4418:  // 小林さんちのメイドラゴン
            return 5036;
        case 4423:  // リトルウィッチアカデミア
            return 4997;
        case 4439:  // ACCA13区監察課
            return 4939;
        case 4433:  // エルドライブ【ēlDLIVE】
            return 4900;
        case 4411:  // BanG Dream!
            return 4992;
        case 4425:  // セイレン
            return 5000;
        case 4464:  // 戦国鳥獣戯画〜乙〜
            return 4999;
        case 4435:  // テイルズ オブ ゼスティリア ザ クロス (第2期)
            return 5089;
        case 5745:  // ひるね姫 ～知らないワタシの物語～
            return 4965;
        case 4394:  // AKIBA’S TRIP -THE ANIMATION-
            return 4989;
        case 4438:  // ちるらん にぶんの壱
            return 4990;
        case 4609:  // 劇場版 トリニティセブン -悠久図書館と錬金術少女-
            return 4923;
        case 4457:  // Spiritpact
            return 5116;
        case 4459:  // レゴ ネックスナイツ (ロックモンスター編)
            return 5117;
        case 4422:  // 超・少年探偵団NEO
            return 4991;
        case 4432:  // チェインクロニクル ～ヘクセイタスの閃～
            return 5038;
        case 4443:  // One Room
            return 5057;
        case 4499:  // 映画 プリキュアドリームスターズ！
            return 6016;
        case 4461:  // キラキラ☆プリキュアアラモード
            return 5075;
        case 4419:  // うらら迷路帖
            return 4940;
        case 5804:  // LUPIN THE IIIRD 血煙の石川五ェ門
            return 4959;
        case 4578:  // RedAsh -GEARWORLD-
            return 5237;
        case 4577:  // げんばのじょう-玄蕃之丞-
            return 5238;
        case 4567:  // ずんだホライずん
            return 5239;
        case 4444:  // CHAOS;CHILD
            return 4901;
        case 4409:  // 鬼平
            return 4984;
        case 4448:  // Rewrite (2ndシーズンMoon編/Terra編)
            return 4995;
        case 4437:  // 銀魂. 烙陽決戦篇
            return 5055;
        case 4414:  // あいまいみー～Surgical Friends～
            return 5054;
        case 4460:  // ナンバカ (第2期)
            return 5071;
        case 4467:  // 闇芝居（4期）
            return 5094;

        // 2018年春
        case 4915:  // グラゼニ
            return 5464;
        case 4918:  // 異世界居酒屋～古都アイテーリアの居酒屋のぶ～
            return 5587;
        case 5290:  // リズと青い鳥
            return 5339;
        case 4848:  // フルメタル･パニック！ Invisible Victory
            return 5026;
        case 4889:  // されど罪人は竜と踊る
            return 5367;
        case 4926:  // 奴隷区 The Animation
            return 5605;
        case 4881:  // ゴールデンカムイ
            return 5407;
        case 5291:  // あさがおと加瀬さん。
            return 5466;
        case 4882:  // Butlers～千年百年物語～
            return 5486;
        case 4904:  // あっくんとカノジョ
            return 5756;
        case 4853:  // ヒナまつり
            return 5487;
        case 4862:  // 宇宙戦艦ティラミス
            return 5480;
        case 4874:  // メジャーセカンド
            return 5758;
        case 4908:  // イナズマイレブン アレスの天秤
            return 5159;
        case 4913:  // メガロボクス
            return 5555;
        case 4857:  // ハイスクールD×D HERO
            return 5569;
        case 4867:  // ニル・アドミラリの天秤
            return 5533;
        case 4873:  // PERSONA5 the Animation
            return 5424;
        case 4841:  // あまんちゅ！～あどばんす～
            return 5600;
        case 4860:  // ガンダムビルドダイバーズ
            return 5728;
        case 4858:  // ラストピリオド -終わりなき螺旋の物語-
            return 5755;
        case 4870:  // 重神機パンドーラ
            return 5560;
        case 4923:  // 実験品家族 -クリーチャーズ・ファミリー・デイズ-
            return 5565;
        case 4854:  // 魔法少女サイト
            return 5710;
        case 4846:  // アイカツフレンズ！
            return 5716;
        case 4864:  // 魔法少女 俺
            return 5625;
        case 4901:  // 若おかみは小学生！
            return 5781;
        case 4885:  // ひそねとまそたん
            return 5629;
        case 4879:  // キャラとおたまじゃくし島
            return 5807;
        case 4877:  // デュエル・マスターズ！
            return 5808;
        case 4891:  // 立花館To Lieあんぐる
            return 5753;
        case 4883:  // ピアノの森
            return 5568;
        case 4892:  // 甘い懲罰～私は看守専用ペット
            return 5744;
        case 4916:  // 僕のヒーローアカデミア (第3期)
            return 5642;
        case 4869:  // ヲタクに恋は難しい
            return 5376;
        // case 4887:  // キラッとプリ☆チャン
        //     return 5715;
        case 4849:  // 食戟のソーマ 餐ノ皿 遠月列車篇
            return 5791;
        case 4893:  // ベイブレードバースト 超ゼツ
            return 5834;
        case 4851:  // ウマ娘 プリティーダービー
            return 5483;
        case 4861:  // 信長の忍び〜姉川・石山篇〜
            return 5692;
        case 4852:  // こみっくがーるず
            return 5709;
        case 4896:  // パズドラ
            return 5829;
        case 4909:  // あはれ！名作くん (第3期)
            return 5856;
        case 4843:  // 多田くんは恋をしない
            return 5544;
        case 4905:  // 蒼天の拳 REGENESIS
            return 5577;
        case 4850:  // Lostorage conflated WIXOSS
            return 5639;
        case 4872:  // ソードアート・オンライン オルタナティブ ガンゲイル・オンライン
            return 5553;
        case 4899:  // キャプテン翼 (2018)
            return 5634;
        case 4911:  // Cutie Honey Universe
            return 5655;
        case 4863:  // 東京喰種トーキョーグール:re
            return 5524;
        case 4868:  // STEINS;GATE 0
            return 5548;
        case 4871:  // 3D彼女 リアルガール
            return 5707;
        case 4842:  // 鬼灯の冷徹 (第弐期その弐)
            return 5667;
        case 4886:  // レイトン ミステリー探偵社 ～カトリーのナゾトキファイル～
            return 5711;
        case 4924:  // 踏切時間
            return 5718;
        case 4855:  // デビルズライン
            return 5538;
        case 4865:  // ありすorありす
            return 5542;
        case 4890:  // かくりよの宿飯
            return 5595;
        case 4888:  // 美男高校地球防衛部HAPPY KISS！
            return 5731;
        case 4856:  // Caligula -カリギュラ-
            return 5603;
        case 4912:  // 鹿楓堂 よついろ日和
            return 5712;
        case 4895:  // ルパン三世 PART5
            return 5691;
        case 4878:  // ゲゲゲの鬼太郎 第6シリーズ
            return 5695;
        case 4903:  // ねこねこ日本史 (第3シリーズ)
            return 5831;
        case 4897:  // わしも-wasimo-(第6シリーズ)
            return 5833;
        case 4932:  // ふるさと 日本の昔ばなし セレクション
            return 5904;
        case 4914:  // テレビ野郎 ナナーナ
            return 5858;
        case 4917:  // フューチャーカード バディファイトX オールスターファイト
            return 5859;
        case 4937:  // マーベル ガーディアンズ・オブ・ギャラクシー
            return 6013;
        case 4947:  // TO BE HEROINE
            return 6041;
        case 4902:  // こねこのチー ポンポンらー大旅行
            return 5830;
        case 4936:  // SNSポリス
            return 5969;
        case 4950:  // フューチャーカード 神バディファイト
            return 6047;
        case 4880:  // 銀河英雄伝説 Die Neue These 邂逅
            return 5324;
        case 4935:  // 黒猫モンロヲ
            return 5942;
        case 4866:  // LOST SONG
            return 5732;
        case 4876:  // お前はまだグンマを知らない
            return 5734;
        case 4898:  // 少年アシベ GO!GO!ゴマちゃん(第3シリーズ)
            return 5832;
        case 4940:  // おしりたんてい 
            return 5757;
        case 4934:  // 妖怪ウォッチ シャドウサイド
            return 5759;
        case 4925:  // レディスポ
            return 5903;
        case 4941:  // カードファイト!! ヴァンガード (2018)
            return 6012;
        case 4999:  // うさぎのマシュー
            return 6151;

        // 2018年夏
        case 5397:  // 未来のミライ
            return 5636;
        case 4981:  // はるかなレシーブ
            return 5375;
        case 4978:  // ゆらぎ荘の幽奈さん
            return 5641;
        case 5011:  // おしえて魔法のペンデュラム～リルリルフェアリル～
            return 6083;
        case 4980:  // 音楽少女
            return 5800;
        case 4989:  // つくもがみ貸します
            return 5575;
        case 4979:  // すのはら荘の管理人さん
            return 5602;
        case 5024:  // 僕のヒーローアカデミア THE MOVIE ～2人の英雄～
            return 5643;
        case 4974:  // 邪神ちゃんドロップキック
            return 5626;
        case 5394:  // 劇場版ポケットモンスター みんなの物語
            return 5773;
        case 4962:  // あそびあそばせ
            return 5720;
        case 4958:  // 異世界魔王と召喚少女の奴隷魔術
            return 5727;
        case 5022:  // ムヒョとロージーの魔法律相談事務所
            return 5820;
        case 4970:  // 京都寺町三条のホームズ
            return 5797;
        case 4956:  // 千銃士
            return 5837;
        case 4984:  // 中間管理録トネガワ
            return 5754;
        case 4985:  // 深夜！天才バカボン
            return 5946;
        case 4954:  // ISLAND (アイランド)
            return 5640;
        case 4968:  // ハイスコアガール
            return 5836;
        case 4976:  // 夢王国と眠れる100人の王子様
            return 5947;
        case 4987:  // 百錬の覇王と聖約の戦乙女
            return 5790;
        case 5753:  // 魔道祖師 前塵篇
            return 7503;
        case 4964:  // ヤマノススメ サードシーズン
            return 5433;
        case 4986:  // 七星のスバル
            return 5708;
        case 4963:  // アイドルマスター シンデレラガールズ劇場 3rd SEASON
            return 5777;
        case 4967:  // ぐらんぶる
            return 5776;
        case 5007:  // 銀魂. 銀ノ魂篇(後半戦)
            return 6094;
        case 5010:  // 天狼 Sirius the Jaeger
            return 5810;
        case 4998:  // オーバーロードIII
            return 5873;
        case 4969:  // 少女☆歌劇 レヴュースタァライト
            return 5760;
        case 4982:  // Free!-Dive to the Future-
            return 6027;
        case 4957:  // Back Street Girls -ゴクドルズ-
            return 6078;
        case 5000:  // じょしおちっ！～2階から女の子が…降ってきた!?～
            return 6092;
        case 5012:  // BanG Dream! ガルパ☆ピコ
            return 6040;
        case 4966:  // ハッピーシュガーライフ
            return 5813;
        case 4996:  // One Room セカンドシーズン
            return 5500;
        case 4977:  // 殺戮の天使
            return 6044;
        case 4955:  // はねバド！
            return 5733;
        case 4971:  // バキ 最凶死刑囚編
            return 5465;
        case 4983:  // 進撃の巨人 Season 3 Part.1
            return 5350;
        case 4995:  // BANANA FISH
            return 5567;
        case 5009:  // 兄に付ける薬はない！2 -快把我哥帯走2-
            return 6069;
        case 5025:  // ざんねんないきもの事典
            return 6209;
        case 4961:  // はたらく細胞
            return 5684;
        case 4965:  // プラネット・ウィズ
            return 5809;
        case 4975:  // アンゴルモア 元寇合戦記
            return 6043;
        case 4973:  // ロード オブ ヴァーミリオン 紅蓮の王
            return 5839;
        case 4988:  // Phantom in the Twilight
            return 5842;
        case 5029:  // ペンギン・ハイウェイ
            return 5762;
        case 5078:  // 劇場版 夏目友人帳 ～うつせみに結ぶ～
            return 6099;
        case 5125:  // オコジョとヤマネ
            return 6138;
        case 5004:  // ミッキーマウスとロードレーサーズ
            return 6091;
        case 5021:  // ミラキュラス レディバグ＆シャノワール
            return 6274;
        case 4959:  // ちおちゃんの通学路
            return 5644;
        case 5031:  // 劇場版 のんのんびより ばけーしょん
            return 5650;
        case 4960:  // ゾイドワイルド
            return 5772;
        case 4994:  // 働くお兄さん！の2！
            return 6009;
        case 4972:  // 悪偶 ‐天才人形‐
            return 6037;
        case 5008:  // スペースバグ
            return 6045;
        case 5003:  // 闇芝居 (6期)
            return 6060;
        case 5020:  // マーベル フューチャー・アベンジャーズ シーズン2
            return 6093;
        case 5035:  // キラキラハッピー★ ひらけ！ここたま
            return 6107;
        case 5005:  // 陰陽師・平安物語
            return 6150;

        // 2018年秋
        case 5071:  // ひもてはうす
            return 6128;
        case 5046:  // SSSS.GRIDMAN
            return 5628;
        case 5101:  // イナズマイレブン オリオンの刻印
            return 6271;
        case 5718:  // HERO MASK
            return 6360;
        case 5055:  // ゴールデンカムイ 第2期
            return 6145;
        case 5093:  // イングレス
            return 5782;
        case 5588:  // Re:ゼロから始める異世界生活 Memory Snow
            return 5485;
        case 5092:  // からくりサーカス
            return 5796;
        case 5082:  // 人外さんの嫁
            return 6136;
        case 5079:  // ラディアン
            return 5725;
        case 5042:  // RELEASE THE SPYCE
            return 5723;
        case 5044:  // DOUBLE DECKER! ダグ&キリル
            return 5802;
        case 5063:  // 俺が好きなのは妹だけど妹じゃない
            return 6001;
        case 5402:  // 劇場版 はいからさんが通る 後編 ～花の東京大ロマン～
            return 6070;
        case 5088:  // 風が強く吹いている
            return 6084;
        case 5050:  // とある魔術の禁書目録III
            return 6106;
        case 5030:  // ジョジョの奇妙な冒険 黄金の風
            return 6132;
        case 5103:  // おこしやす、ちとせちゃん
            return 6189;
        case 5059:  // やがて君になる
            return 6010;
        case 5128:  // 聖闘士星矢 セインティア翔
            return 5120;
        case 5106:  // FAIRY TAIL ファイナルシリーズ
            return 6005;
        case 5098:  // ほら、耳がみえてるよ！
            return 6242;
        case 5077:  // 叛逆性ミリオンアーサー
            return 5811;
        case 5069:  // 東京喰種トーキョーグール:re 最終章
            return 6117;
        case 5072:  // RErideD -刻越えのデリダ-
            return 5819;
        case 5102:  // ほしの島のにゃんこ
            return 6214;
        case 5048:  // 転生したらスライムだった件
            return 5789;
        case 5045:  // アイドルマスター SideM 理由あってMini!
            return 6231;
        case 5080:  // ツルネ ―風舞高校弓道部―
            return 5574;
        case 5060:  // 色づく世界の明日から
            return 5799;
        case 5051:  // 寄宿学校のジュリエット
            return 5795;
        case 5053:  // 青春ブタ野郎はバニーガール先輩の夢を見ない
            return 5792;
        case 5061:  // となりの吸血鬼さん
            return 5840;
        case 5070:  // 学園BASARA
            return 5948;
        case 5057:  // ゾンビランドサガ
            return 6159;
        case 5043:  // あかねさす少女
            return 5812;
        case 5054:  // うちのメイドがウザすぎる！
            return 5944;
        case 5083:  // 爆釣バーハンター
            return 6108;
        case 5049:  // ソードアート・オンライン アリシゼーション
            return 5550;
        case 5203:  // その時、カノジョは。
            return 6243;
        case 5052:  // ゴブリンスレイヤー
            return 6077;
        case 4484:  // 宇宙戦艦ヤマト2202 愛の戦士たち
            return 6201;
        case 5076:  // メルクストーリア -無気力少年と瓶の中の少女-
            return 6202;
        case 5056:  // ソラとウミのアイダ
            return 5841;
        case 5047:  // 宇宙戦艦ティラミスII
            return 6146;
        case 5068:  // ガイコツ書店員 本田さん
            return 5498;
        case 5109:  // スーパーブック
            return 6278;
        case 5115:  // 走り続けてよかったって。
            return 6248;
        case 5074:  // でびどる！
            return 6252;
        case 5100:  // BAKUMATSU ～恋愛幕末カレシ 外伝～
            return 5835;
        case 5099:  // 逆転裁判 ～その「真実」、異議あり！～ Season2
            return 6142;
        case 5065:  // 抱かれたい男1位に脅されています。
            return 6147;
        case 5062:  // アニマエール！
            return 6183;
        case 5075:  // 閃乱カグラ SHINOVI MASTER -東京妖魔篇-
            return 6188;
        case 5089:  // 狐狸之声
            return 6208;
        case 5292:  // 続・終物語
            return 5652;
        case 5058:  // 火ノ丸相撲
            return 5821;
        case 5064:  // ベルゼブブ嬢のお気に召すまま。
            return 5943;
        case 5902:  // 魔法少女リリカルなのは Detonation
            return 5998;
        case 5108:  // 愛玩怪獣
            return 6279;
        case 5104:  // ピングー in ザ・シティ (第2シリーズ)
            return 6281;
        case 5066:  // ユリシーズ ジャンヌ・ダルクと錬金の騎士
            return 6026;
        case 5067:  // CONCEPTION
            return 6029;
        case 5105:  // グラゼニ シーズン2
            return 6135;
        case 5086:  // 蒼天の拳 REGENESIS 第2期
            return 6148;
        case 5553:  // 映画 妖怪ウォッチ FOREVER FRIENDS
            return 6193;
        case 5096:  // 軒轅剣・蒼き曜
            return 6200;
        case 5097:  // トロールズ シング・ダンス・ハグ！
            return 6213;
        case 5039:  // Thunderbolt Fantasy 東離劍遊紀 2
            return 6270;
        case 5112:  // 終電後､カプセルホテルで､上司に微熱伝わる夜｡
            return 6272;
        case 5116:  // おとなの防具屋さん
            return 6276;
        case 5091:  // マーベル スパイダーマン (第2シーズン)
            return 6275;
        case 5130:  // おしりたんてい (第2シリーズ)
            return 6372;

        // 2018年冬
        case 4773:  // スロウスタート
            return 5455;
        case 4813:  // 七つの大罪 戒めの復活 (第2期)
            return 5458;
        case 4780:  // ミイラの飼い方
            return 5475;
        case 4788:  // ダーリン・イン・ザ・フランキス
            return 5361;
        case 4804:  // 恋は雨上がりのように
            return 5179;
        case 5702:  // A.I.C.O. Incarnation
            return 5409;
        case 4765:  // だがしかし2
            return 5410;
        case 4784:  // グランクレスト戦記
            return 5453;
        case 4789:  // 弱虫ペダル GLORY LINE
            return 5460;
        case 4794:  // ダメプリ ANIME CARAVAN
            return 5456;
        case 4790:  // カードキャプターさくら クリアカード編
            return 5065;
        case 4785:  // ポプテピピック
            return 5229;
        case 4781:  // からかい上手の高木さん
            return 5546;
        case 4770:  // BEATLESS ビートレス
            return 5530;
        case 4796:  // キリングバイツ
            return 5532;
        case 4791:  // サンリオ男子
            return 5454;
        case 4771:  // 博多豚骨ラーメンズ
            return 5412;
        case 4792:  // バジリスク ～桜花忍法帖～
            return 5579;
        case 4766:  // たくのみ。
            return 5588;
        case 4819:  // 25歳の女子高生
            return 5604;
        case 4775:  // 続 刀剣乱舞-花丸-
            return 5457;
        case 4801:  // 新幹線変形ロボ シンカリオン THE ANIMATION
            return 5547;
        case 5019:  // 劇場版「進撃の巨人」Season2～覚醒の咆哮～
            return 5586;
        case 4772:  // メルヘン・メドヘン
            return 5593;
        case 4764:  // 刀使ノ巫女
            return 5415;
        case 4776:  // 斉木楠雄のΨ難 (第2期)
            return 5594;
        case 4825:  // 銀の墓守りII
            return 5452;
        case 4799:  // 伊藤潤二「コレクション」
            return 5624;
        case 4769:  // アイドリッシュセブン
            return 5484;
        case 4793:  // 学園ベビーシッターズ
            return 5541;
        case 4786:  // 宇宙よりも遠い場所
            return 5592;
        case 4838:  // Spiritpact-黄泉の契り-
            return 5653;
        case 4948:  // ミルキーパニック twelve
            return 6050;
        case 4807:  // 映画 中二病でも恋がしたい！ -Take On Me-
            return 5327;
        case 4767:  // デスマーチからはじまる異世界狂想曲
            return 5408;
        case 4779:  // ヴァイオレット・エヴァーガーデン
            return 5362;
        case 4832:  // Fate/EXTRA Last Encore
            return 5110;
        case 5214:  // さよならの朝に約束の花をかざろう
            return 5357;
        case 5817:  // 文豪ストレイドッグス DEAD APPLE
            return 5745;
        case 4763:  // citrus【シトラス】
            return 5349;
        case 4782:  // ハクメイとミコチ
            return 5578;
        case 4798:  // オーバーロードⅡ
            return 5531;
        case 4783:  // ゆるキャン△
            return 5459;
        case 4768:  // りゅうおうのおしごと！
            return 5556;
        case 4670:  // 三ツ星カラーズ
            return 5400;
        case 4777:  // ラーメン大好き小泉さん
            return 5233;
        case 4845:  // レゴ ニンジャゴー(6)
            return 5770;
        case 4800:  // 七つの美徳
            return 5606;
        case 4816:  // 刻刻
            return 5559;
        case 4820:  // 怪獣娘～ウルトラ怪獣擬人化計画～ (第2期) 
            return 5451;
        case 4834:  // HUGっと！プリキュア
            return 5623;
        case 5127:  // 新妹魔王の契約者 DEPARTURES
            return 5585;
        case 4833:  // 衛宮さんちの今日のごはん
            return 5660;
        case 4803:  // 働くお兄さん！
            return 5630;
        case 4821:  // 一人之下 the outcast 羅天大醮篇
            return 5666;
        case 5085:  // 戦隊ヒーロー スキヤキフォース -ぐんまの平和を願うシーズン え、また？-
            return 5719;
        case 4944:  // TIME DRIVER 僕らが描いた未来
            return 6042;
        case 5426:  // 劇場版 マジンガーZ ／ INFINITY
            return 5366;
        case 4795:  // 覇穹 封神演義
            return 5406;
        case 4806:  // まめねこ
            return 5590;
        case 4824:  // ポチっと発明 ピカちんキット
            return 5622;
        case 4949:  // Midnight Crazy Trail
            return 5566;
        case 5213:  // 劇場版Infini-T Force／ガッチャマン さらば友よ
            return 5747;
        case 4815:  // gdメン
            return 5598;
        case 4818:  // 剣王朝
            return 5651;
        case 4812:  // うちのウッチョパス
            return 5663;
        case 5232:  // 映画プリキュアスーパースターズ！
            return 5672;
        case 4837:  // がん がん がんこちゃん (第2シリーズ)
            return 5729;
        case 4943:  // えんぎもん
            return 6049;

        // 2019年春
        case 5271:  // 文豪ストレイドッグス (第3期)
            return 6182;
        case 5338:  // プロメア
            return 6306;
        case 5261:  // RobiHachi
            return 6357;
        case 5247:  // みだらな青ちゃんは勉強ができない
            return 6400;
        case 5329:  // 進撃の巨人 Season 3 Part.2
            return 6498;
        case 5267:  // 爆丸バトルプラネット
            return 6510;
        case 5248:  // フルーツバスケット 1st Season
            return 6355;
        case 5283:  // さらざんまい
            return 5780;
        case 5272:  // ワンパンマン (第2期)
            return 5495;
        case 5287:  // MIX
            return 6199;
        case 5276:  // 八月のシンデレラナイン
            return 6203;
        case 5240:  // 賢者の孫
            return 5499;
        case 5297:  // BAKUMATSUクライシス
            return 6410;
        case 5253:  // 鬼滅の刃
            return 6089;
        case 5245:  // ひとりぼっちの○○生活
            return 5838;
        case 5256:  // 超可動ガール1/6
            return 6260;
        case 5252:  // 消滅都市
            return 6076;
        case 5277:  // ストライクウィッチーズ 501部隊発進しますっ！
            return 6165;
        case 5309:  // 真夜中のオカルト公務員
            return 6137;
        case 5243:  // なんでここに先生が!?
            return 6286;
        case 5260:  // なむあみだ仏っ！-蓮台 UTENA-
            return 6216;
        case 5299:  // この音とまれ！
            return 6179;
        case 5614:  // 映画 おしりたんてい カレーなる じけん
            return 7612;
        case 5303:  // キャロル&チューズデイ
            return 5787;
        case 5254:  // アイドルマスター シンデレラガールズ劇場 CLIMAX SEASON
            return 6402;
        case 5241:  // ぼくたちは勉強ができない
            return 6264;
        case 5249:  // 世話やきキツネの仙狐さん
            return 6401;
        case 5234:  // 洗い屋さん！～俺とアイツが女湯で！？～
            return 6512;
        case 5239:  // アイカツフレンズ！～かがやきのジュエル～
            return 6480;
        case 5275:  // 群青のマグメル
            return 6023;
        case 5661:  // ULTRAMAN
            return 5611;
        case 5258:  // ノブナガ先生の幼な妻
            return 6393;
        case 5330:  // 機動戦士ガンダム THE ORIGIN 前夜 赤い彗星
            return 6348;
        case 5266:  // 八十亀ちゃんかんさつにっき
            return 6362;
        case 5257:  // 女子かう生
            return 6258;
        case 5274:  // ダイヤのA act II
            return 6371;
        case 5251:  // この世の果てで恋を唄う少女 YU-NO
            return 6284;
        case 5259:  // Fairy gone フェアリーゴーン
            return 6467;
        case 5685:  // 青春ブタ野郎はゆめみる少女の夢を見ない
            return 6257;
        case 5246:  // 川柳少女
            return 6373;
        // case 4887:  // キラッとプリ☆チャン シーズン2
        //     return 6546;
        case 5281:  // えいがのおそ松さん
            return 6232;
        case 5311:  // ほら、耳がみえてるよ！ (第2シリーズ)
            return 6631;
        case 5278:  // けだまのゴンじろー
            return 6494;
        case 5812:  // 劇場版 うたの☆プリンスさまっ♪ マジLOVEキングダム
            return 5656;
        case 5242:  // KING OF PRISM -Shiny Seven Stars-
            return 6109;
        case 5279:  // パウ・パトロール
            return 6509;
        case 5707:  // 劇場版 響け！ユーフォニアム～誓いのフィナーレ～
            return 5340;
        case 5802:  // LUPIN THE IIIRD 峰不二子の嘘
            return 6525;
        case 5318:  // スーパーブック シーズン2
            return 6636;
        case 5592:  // LAIDBACKERS-レイドバッカーズ-
            return 6314;
        case 5250:  // 叛逆性ミリオンアーサー 第2シーズン
            return 6523;
        case 5293:  // 少年アシベ GO!GO!ゴマちゃん(第4シリーズ)
            return 6538;
        case 5300:  // 妖怪ウォッチ！(2019新シリーズ)
            return 6544;
        case 5307:  // 四月一日さん家の
            return 6547;
        case 5302:  // デュエル・マスターズ！！
            return 6586;
        case 5306:  // フリージ
            return 6589;
        case 5319:  // 岐阜のたてかよこ
            return 6635;
        case 5244:  // 異世界かるてっと
            return 6304;
        case 5369:  // きみと、波にのれたら
            return 6317;
        case 5334:  // カードファイト!! ヴァンガード (続・高校生編)
            return 6470;
        case 5298:  // ねこねこ日本史 (第4シリーズ)
            return 6537;
        case 5273:  // 凹凸世界
            return 6548;
        case 5289:  // わしも-wasimo-(第7シリーズ)
            return 6585;
        case 5301:  // あはれ！名作くん (第4期)
            return 6588;
        case 5489:  // テレビ野郎 ナナーナ わくわく洞窟ランド
            return 6594;
        case 5384:  // CENCOROLL CONNECT -センコロール コネクト-
            return 6613;

        // 2019年夏
        case 5361:  // Dr.STONE
            return 6358;
        case 5345:  // とある科学の一方通行
            return 6300;
        case 5374:  // ギヴン
            return 6621;
        case 5342:  // ロード・エルメロイII世の事件簿 -魔眼蒐集列車 Grace note-
            return 6443;
        case 5373:  // スタミュ (第3期)
            return 5551;
        case 5351:  // 異世界チート魔術師
            return 6003;
        case 5557:  // 7SEEDS
            return 6363;
        case 5346:  // 通常攻撃が全体攻撃で二回攻撃のお母さんは好きですか？
            return 6313;
        case 5359:  // 炎炎ノ消防隊
            return 6337;
        case 5343:  // ダンジョンに出会いを求めるのは間違っているだろうか II
            return 5752;
        case 5354:  // ナカノヒトゲノム【実況中】
            return 6071;
        case 5350:  // ありふれた職業で世界最強
            return 5627;
        case 5355:  // 手品先輩
            return 6326;
        case 5352:  // 魔王様、リトライ！
            return 6315;
        case 5366:  // コップクラフト
            return 6442;
        case 5360:  // かつて神だった獣たちへ
            return 6471;
        case 5364:  // まちカドまぞく
            return 6479;
        case 5399:  // トライナイツ
            return 6622;
        case 5363:  // あんさんぶるスターズ！
            return 6028;
        case 5358:  // 荒ぶる季節の乙女どもよ。
            return 6370;
        case 5390:  // ヴィンランド・サガ
            return 5818;
        case 5353:  // ダンベル何キロ持てる？
            return 6463;
        case 5401:  // ざんねんないきもの事典 (第2シリーズ)
            return 7811;
        case 5365:  // 彼方のアストラ
            return 6472;
        case 5349:  // 可愛ければ変態でも好きになってくれますか？
            return 6513;
        case 5347:  // からかい上手の高木さん2
            return 6446;
        case 5357:  // グランベルム
            return 6532;
        case 5391:  // 天気の子
            return 6417;
        // case 5411:  // ゼノンザード THE ANIMATION 第0話
        //     return 6942;
        case 5356:  // ソウナンですか？
            return 6529;
        case 5344:  // 戦姫絶唱シンフォギアXV
            return 6396;
        case 5691:  // ドラゴンクエスト ユア・ストーリー
            return 6493;
        case 5348:  // 女子高生の無駄づかい
            return 6322;
        case 5362:  // Re:ステージ！ ドリームデイズ♪
            return 6154;
        case 5863:  // HERO MASK PartII
            return 6812;
        case 5451:  // みにゆり
            return 6951;
        case 5826:  // 魔道祖師 羨雲編
            return 7504;
        case 5425:  // HELLO WORLD
            return 6394;
        case 5376:  // 凹凸世界 シーズン2
            return 6768;
        case 5387:  // おしりたんてい (第3シリーズ)
            return 6789;
        case 5379:  // 胡蝶綺 ～若き信長～
            return 6441;
        case 5852:  // ミュウツーの逆襲 EVOLUTION
            return 6447;
        case 5471:  // モノのかみさま ここたま
            return 6960;
        case 5367:  // 指先から本気の熱情-幼なじみは消防士-
            return 6673;
        case 5546:  // ケンガンアシュラ
            return 5700;
        case 5393:  // ビジネスフィッシュ
            return 6763;
        case 5438:  // かいじゅうステップ ワンダバダ
            return 6792;
        case 5409:  // カードファイト!! ヴァンガード (新右衛門編)
            return 6933;
        case 5924:  // SDガンダムワールド 三国創傑伝
            return 6350;
        case 5382:  // 闇芝居 (7期)
            return 6674;
        case 5375:  // BEM
            return 6496;
        case 5341:  // うちの娘の為ならば、俺はもしかしたら魔王も倒せるかもしれない。
            return 6514;
        case 5381:  // 博多明太！ぴりからこちゃん
            return 6590;

        // 2019年秋
        case 5474:  // シルバニアファミリー ミニストーリー クローバー
            return 6976;
        case 5462:  // ぬるぺた
            return 6941;
        case 5898:  // 劇場版 新幹線変形ロボ シンカリオン 未来からきた神速のALFA-X
            return 6977;
        case 5465:  // 僕のヒーローアカデミア (第4期)
            return 6282;
        case 5445:  // 歌舞伎町シャーロック
            return 6329;
        case 5414:  // 慎重勇者 ～この勇者が俺TUEEEくせに慎重すぎる～
            return 6330;
        case 5455:  // BEASTARS
            return 6497;
        case 5443:  // 魔入りました！入間くん
            return 6542;
        case 5447:  // 空の青さを知る人よ
            return 6549;
        case 5413:  // ソードアート・オンライン アリシゼーション War of Underworld
            return 6587;
        case 5454:  // ファンタシースターオンライン2 エピソード・オラクル
            return 6624;
        case 5456:  // 七つの大罪 神々の逆鱗
            return 6649;
        case 5416:  // ぼくたちは勉強ができない！
            return 6783;
        case 5417:  // 私、能力は平均値でって言ったよね！
            return 6787;
        case 5457:  // 神田川JET GIRLS
            return 6872;
        case 5453:  // どるふろ -癒し編-
            return 6953;
        case 5412:  // ハイスコアガール II
            return 6611;
        case 5441:  // 厨病激発ボーイ
            return 6616;
        case 5501:  // ポケットモンスター (2019年版)
            return 6961;
        case 5440:  // アフリカのサラリーマン
            return 6820;
        case 5439:  // Z/X Code reunion
            return 6777;
        case 5480:  // 兄に付ける薬はない！3 -快把我哥帯走3-
            return 6764;
        case 5903:  // Levius レビウス
            return 6610;
        case 5463:  // ノー・ガンズ・ライフ
            return 6614;
        case 5419:  // ライフル・イズ・ビューティフル
            return 6644;
        case 5434:  // Fairy gone フェアリーゴーン 2クール目
            return 6675;
        case 5427:  // XL上司。
            return 6917;
        case 5491:  // PSYCHO-PASS サイコパス 3
            return 6524;
        case 5418:  // 食戟のソーマ 神ノ皿
            return 6757;
        case 5449:  // アズールレーン
            return 6254;
        case 5421:  // 放課後さいころ倶楽部
            return 6259;
        case 5424:  // アサシンズプライド
            return 6319;
        case 5428:  // あひるの空
            return 5775;
        case 5437:  // バビロン
            return 5817;
        case 5460:  // ちはやふる3
            return 6336;
        case 5436:  // この音とまれ！ 第2クール
            return 6774;
        case 5444:  // アイカツオンパレード！
            return 6934;
        case 5415:  // 俺を好きなのはお前だけかよ
            return 6303;
        case 5431:  // GRANBLUE FANTASY The Animation Season2
            return 6521;
        case 5569:  // ゆるゆり、
            return 6924;
        case 5435:  // Fate/Grand Order -絶対魔獣戦線バビロニア-
            return 6192;
        case 5420:  // 本好きの下剋上 司書になるためには手段を選んでいられません
            return 6522;
        case 5432:  // 警視庁 特務部 特殊凶悪犯対策室 第七課 -トクナナ-
            return 6612;
        case 5671:  // Re:ゼロから始める異世界生活 氷結の絆
            return 6457;
        case 5464:  // 星合の空
            return 6233;
        case 5803:  // ルパン三世 THE FIRST
            return 6807;
        case 5423:  // 戦×恋
            return 6682;
        case 5429:  // 旗揚！けものみち
            return 6483;
        case 5459:  // スタンドマイヒーローズ PIECE OF TRUTH
            return 6256;
        case 5452:  // 冴えない彼女の育てかた Fine
            return 5705;
        case 5442:  // ラディアン 第2シリーズ
            return 6536;
        case 5422:  // 超人高校生たちは異世界でも余裕で生き抜くようです！
            return 6623;
        case 5500:  // 無限の住人 -IMMORTAL-
            return 6672;
        case 5448:  // ゾイドワイルド ZERO
            return 6819;
        case 5473:  // 耐え子の日常
            return 6949;
        case 5446:  // おちゃめなシモン
            return 6952;
        case 5461:  // 天華百剣 ～めいじ館へようこそ！～
            return 6922;
        case 5510:  // むかしケイバなし
            return 7186;
        case 5486:  // アニメ  ボス・ベイビー
            return 6982;
        case 5508:  // ルパン三世 プリズン・オブ・ザ・パスト
            return 7057;
        case 5549:  // 妖怪ウォッチJam 妖怪学園Y ～Nとの遭遇～
            return 7127;
        case 5983:  // 斉木楠雄のΨ難 Ψ始動編
            return 6999;
        case 5430:  // 浦島坂田船の日常
            return 6873;
        case 5477:  // ガンダムビルドダイバーズRe:RISE
            return 6349;
        case 5468:  // BLACKFOX
            return 6439;
        case 5458:  // 真・中華一番！
            return 6473;
        case 5433:  // ACTORS -Songs Connection-
            return 6598;
        case 5678:  // フラグタイム
            return 6618;
        case 5478:  // エッグカー
            return 6978;
        case 5479:  // GO!GO!アトム
            return 6979;

        // 2019年冬
        case 5395:  // キャプテン・バル
            return 6681;
        case 5140:  // ぱすてるメモリーズ
            return 6104;
        case 5149:  // 盾の勇者の成り上がり
            return 6219;
        case 5151:  // 賭ケグルイ××
            return 5671;
        case 5188:  // どろろ (2019)
            return 5816;
        case 5143:  // 私に天使が舞い降りた！
            return 6130;
        case 5156:  // マナリアフレンズ
            return 4621;
        case 5145:  // 五等分の花嫁
            return 6205;
        case 5166:  // サークレット・プリンセス
            return 6215;
        case 5155:  // 荒野のコトブキ飛行隊
            return 6253;
        case 5154:  // モブサイコ100 II
            return 6000;
        case 5144:  // 3D彼女 リアルガール 第2シーズン
            return 6131;
        case 5137:  // 魔法少女特殊戦あすか
            return 6181;
        case 5163:  // 明治東亰恋伽
            return 6210;
        case 5165:  // けものフレンズ2
            return 6245;
        case 5147:  // エガオノダイカ
            return 6311;
        case 5161:  // デート・ア・ライブIII
            return 6312;
        case 5148:  // みにとじ
            return 6334;
        case 5186:  // ピアノの森 第2シリーズ
            return 6152;
        case 5150:  // ガーリー・エアフォース
            return 6082;
        case 5206:  // スター☆トゥインクルプリキュア
            return 6403;
        case 5159:  // 約束のネバーランド
            return 6079;
        case 5157:  // 上野さんは不器用
            return 6073;
        case 5138:  // かぐや様は告らせたい〜天才たちの恋愛頭脳戦〜
            return 6081;
        case 5142:  // 不機嫌なモノノケ庵 續
            return 6134;
        case 5167:  // ブギーポップは笑わない
            return 5793;
        case 5139:  // えんどろ～！
            return 6180;
        case 5136:  // ドメスティックな彼女
            return 6170;
        case 5175:  // 劇場版 ラブライブ！サンシャイン!! The School Idol Movie Over the Rainbow
            return 5696;
        case 5896:  // 映画 プリキュアミラクルユニバース
            return 6449;
        case 5152:  // ケムリクサ (TVシリーズ)
            return 5740;
        case 5200:  // revisions リヴィジョンズ
            return 5788;
        case 5675:  // PSYCHO-PASS サイコパス Sinners of the System Case.3「恩讐の彼方に＿＿」
            return 5785;
        case 5408:  // グリザイア：ファントムトリガー THE ANIMATION
            return 5430;
        case 5153:  // 同居人はひざ、時々、頭のうえ。
            return 6207;
        case 5146:  // グリムノーツ The Animation
            return 6221;
        case 5160:  // 雨色ココア sideG
            return 6318;
        case 5672:  // 劇場版 トリニティセブン -天空図書館と真紅の魔王-
            return 6157;
        case 5192:  // 臨死!! 江古田ちゃん
            return 6217;
        case 5673:  // PSYCHO-PASS サイコパス Sinners of the System Case.1「罪と罰」
            return 5783;
        case 5158:  // BanG Dream! 2nd Season
            return 6038;
        case 5171:  // Dimension ハイスクール
            return 6302;
        case 5201:  // バーチャルさんはみている
            return 6412;
        case 5173:  // ぷそ煮コミ
            return 6413;
        case 5191:  // パパだって、したい
            return 6432;
        case 5189:  // 真夜中のボイトレ男子
            return 6431;
        case 5386:  // チャックシメゾウ
            return 6680;
        case 5218:  // カワウソラボ
            return 6459;
        case 5674:  // PSYCHO-PASS サイコパス Sinners of the System Case.2「First Guardian」
            return 5784;
        case 5141:  // W'z《ウィズ》
            return 5814;
        case 5564:  // 劇場版 幼女戦記
            return 5674;
        case 5164:  // B-PROJECT～絶頂＊エモーション～
            return 6177;
        case 5162:  // バミューダトライアングル ～カラフル・パストラーレ～
            return 6234;
        case 5193:  // フライングベイビーズ
            return 6235;
        case 5215:  // ルパン三世 グッバイ・パートナー
            return 6435;
        case 5229:  // 今日もツノがある
            return 6437;
        case 5194:  // 一騎当千 Western Wolves
            return 6466;
        case 5222:  // スパイダーマン：スパイダーバース
            return 6511;
        case 5371:  // Hello WeGo!
            return 6667;
        case 5385:  // 斗え！スペースアテンダントアオイ
            return 6679;

        // 2020年春
        case 5599:  // かくしごと
            return 7122;
        case 5616:  // 継つぐもも
            return 6526;
        case 5615:  // 文豪とアルケミスト 〜審判ノ歯車〜
            return 7226;
        case 5601:  // 邪神ちゃんドロップキック’
            return 6481;
        case 5593:  // 八男って、それはないでしょう！
            return 6416;
        case 5612:  // ミュークルドリーミー
            return 6926;
        case 5622:  // 波よ聞いてくれ
            return 6991;
        case 5621:  // LISTENERS
            return 7274;
        case 5617:  // 社長、バトルの時間です！
            return 7171;
        case 5596:  // かぐや様は告らせたい？～天才たちの恋愛頭脳戦～
            return 7051;
        case 5634:  // BNA ビー・エヌ・エー
            return 6798;
        case 4887:  // キラッとプリ☆チャン シーズン3
            return 7427;
        case 5636:  // グレイプニル
            return 6527;
        case 5624:  // アルテ
            return 6814;
        case 5610:  // フルーツバスケット 2nd Season
            return 6948;
        case 5630:  // 新サクラ大戦 the Animation
            return 6945;
        case 5598:  // 球詠
            return 6766;
        case 5666:  // 別冊オリンピア・キュクロス
            return 7328;
        case 5607:  // のりものまん モービルランドのカークン
            return 7383;
        case 5618:  // 乙女ゲームの破滅フラグしかない悪役令嬢に転生してしまった…
            return 6321;
        case 5635:  // 神之塔 -Tower of God-
            return 7325;
        case 5602:  // プリンセスコネクト！Re:Dive
            return 6540;
        case 5640:  // 困ったじいさん
            return 7212;
        case 5690:  // 大家さんと僕 シーズン2
            return 7534;
        case 5600:  // 本好きの下剋上 司書になるためには手段を選んでいられません 第2部
            return 7180;
        case 5631:  // イエスタデイをうたって
            return 7158;
        case 5637:  // アルゴナビス from BanG Dream!
            return 7086;
        case 5719:  // バキ 大擂台賽編
            return 7378;
        case 5721:  // BanG Dream! ガルパ☆ピコ～大盛り～
            return 7406;
        case 5651:  // ねこねこ日本史 (第5シリーズ)
            return 7417;
        case 5611:  // 遊☆戯☆王SEVENS
            return 7210;
        case 5613:  // メジャーセカンド 第2シリーズ
            return 7002;
        case 5639:  // ぽっこりーず
            return 7320;
        case 5625:  // シャドウバース
            return 6988;
        case 5642:  // わしも-wasimo-(第8シリーズ)
            return 7414;
        case 5663:  // ガンダムビルドダイバーズRe:RISE 2nd Season
            return 7244;
        case 5632:  // ハクション大魔王2020
            return 7245;
        case 5681:  // カードファイト!! ヴァンガード外伝 イフ-if-
            return 7415;
        case 5619:  // 白猫プロジェクト ZERO CHRONICLE
            return 6414;
        case 5606:  // 啄木鳥探偵處
            return 6603;
        case 5638:  // 俺の指で乱れろ。～閉店後二人きりのサロンで…～
            return 7339;
        case 5604:  // おしりたんてい (第4シリーズ)
            return 7371;
        case 5658:  // ぷそ煮コミおかわり
            return 7428;
        case 5696:  // ステイングベイビーズ
            return 7540;
        case 5547:  // A3! SEASON SPRING & SUMMER
            return 6475;
        case 5627:  // もっと！まじめにふまじめ かいけつゾロリ
            return 6793;
        case 5626:  // トミカ絆合体 アースグランナー
            return 7264;
        case 5731:  // テレビ野郎 ナナーナ 怪物クラーケンを追え！
            return 7375;
        case 5680:  // むかしケイバなし (第2期)
            return 7511;
        case 5645:  // あはれ！名作くん (第5期)
            return 7377;
        case 5659:  //  四月一日さん家と
            return 7326;
        case 5816:  // ベイブレードバースト スパーキング
            return 7387;
        case 5646:  // デュエル・マスターズ キング
            return 7388;

        // 2020年夏
        case 5715:  // 耐え子の日常 第2期
            return 7543;
        case 5595:  // やはり俺の青春ラブコメはまちがっている。完
            return 6584;
        case 5703:  // 恋とプロデューサー ～EVOL×LOVE～
            return 6800;
        case 5716:  // GREAT PRETENDER
            return 6801;
        case 5717:  // アラド: 逆転の輪
            return 7549;
        case 5694:  // 魔王学院の不適合者 ～史上最強の魔王の始祖、転生して子孫たちの学校へ通う～
            return 6983;
        case 5609:  // 食戟のソーマ 豪ノ皿
            return 7219;
        case 5603:  // ソードアート・オンライン アリシゼーション War of Underworld ‐THE LAST SEASON‐
            return 7234;
        case 5701:  // デカダンス
            return 6795;
        case 5695:  // 八月のシンデレラナイン Re:fine
            return 7539;
        case 5711:  // GIBIATE the Animation
            return 6804;
        case 5722:  // 戦乙女の食卓
            return 7550;
        case 5732:  // ノクターンブギ
            return 7594;
        case 5705:  // Lapis Re:LiGHTs ラピスリライツ
            return 7203;
        case 5706:  // ピーター・グリルと賢者の時間
            return 6968;
        case 5698:  // モンスター娘のお医者さん
            return 7121;
        case 5728:  // 超普通都市カシワ伝説R
            return 7514;
        case 5620:  // 放課後ていぼう日誌
            return 6646;
        case 6012:  // 映画 おしりたんてい テントウムシいせきの なぞ
            return 7613;
        case 5771:  // おちゃめなシモン (第2シリーズ)
            return 7670;
        case 5714:  // 炎炎ノ消防隊 弐ノ章
            return 7232;
        case 5653:  // 富豪刑事 Balance:UNLIMITED
            return 7271;
        case 5628:  // デジモンアドベンチャー：
            return 7268;
        case 5710:  // 忍者コレクション
            return 7548;
        case 5708:  // THE GOD OF HIGH SCHOOL ゴッド・オブ・ハイスクール
            return 7498;
        case 5713:  // GETUP! GETLIVE! #げらげら
            return 7426;
        case 5709:  // うまよん
            return 6415;
        case 5700:  // ド級編隊エグゼロス
            return 7056;
        case 5692:  // 宇崎ちゃんは遊びたい！
            return 7319;
        case 5742:  // ふしぎ駄菓子屋 銭天堂
            return 7596;
        case 5724:  // 異常生物見聞録
            return 6533;
        case 5712:  // 巨人族の花嫁
            return 7395;
        case 5727:  // ポータウンのなかまたち
            return 7587;
        // case 5701:  // デカダンス 第5.5話「install」
        //     return 7622;
        case 5697:  // Re:ゼロから始める異世界生活 2ndシーズン
            return 6582;
        case 5725:  // ムヒョとロージーの魔法律相談事務所 第2期
            return 6758;
        case 5623:  // 天晴爛漫！
            return 7000;
        case 5693:  // 彼女、お借りします
            return 7202;
        case 5629:  // ノー・ガンズ・ライフ 第2期
            return 7229;
        case 5733:  // バジャのスタジオ ～バジャのみた海～
            return 7589;
        case 5740:  // オオカミさんは食べられたい
            return 7627;

        // 2020年秋
        case 5789:  // かえるのピクルス -きもちのいろ-
            return 7658;
        case 5777:  // 第501統合戦闘航空団 ストライクウィッチーズ ROAD to BERLIN
            return 6166;
        case 5739:  // ご注文はうさぎですか？BLOOM
            return 6267;
        case 5754:  // ゴールデンカムイ 第3期
            return 6799;
        case 5755:  // 魔法科高校の劣等生 来訪者編
            return 6984;
        case 5761:  // アサルトリリィ BOUQUET
            return 6997;
        case 5769:  // キミと僕の最後の戦場、あるいは世界が始まる聖戦
            return 7052;
        case 5779:  // ドラゴンクエスト ダイの大冒険 (2020年版)
            return 7208;
        case 5794:  // キングスレイド 意志を継ぐものたち
            return 7499;
        case 5776:  // 神達に拾われた男
            return 7336;
        case 5778:  // 神様になった日
            return 7507;
        case 5756:  // くまクマ熊ベアー
            return 7248;
        case 5759:  // 戦翼のシグルドリーヴァ
            return 7368;
        case 5782:  // ハイキュー!! TO THE TOP 第2クール
            return 7420;
        case 5792:  // D4DJ First Mix
            return 6653;
        case 5747:  // 安達としまむら
            return 6664;
        case 5827:  // 進撃の巨人 The Final Season Part.1
            return 6779;
        case 5757:  // ひぐらしのなく頃に業
            return 7400;
        case 5810:  // せいぜいがんばれ！魔法少女くるみ (第3期)
            return 7630;
        case 5770:  // アクダマドライブ
            return 7386;
        case 5765:  // 『ヒプノシスマイク -Division Rap Battle-』Rhyme Anima
            return 7177;
        case 5807:  // スーパーブック シーズン3
            return 7697;
        case 5800:  // 兄に付ける薬はない！4 -快把我哥帯走4-
            return 7593;
        case 5784:  // 禍つヴァールハイト -ZUERST-
            return 7489;
        case 5783:  // 半妖の夜叉姫 -戦国御伽草子-
            return 7508;
        case 5775:  // 憂国のモリアーティ
            return 7218;
        case 5791:  // 秘密結社 鷹の爪 ～ゴールデン・スペル～
            return 7636;
        case 5790:  // NOBLESSE -ノブレス-
            return 7663;
        case 5824:  // ゲボイデ＝ボイデ
            return 7731;
        case 5829:  // 東京ガンボ
            return 7761;
        case 5608:  // アイドリッシュセブン Second BEAT!
            return 6163;
        case 5809:  // 最響カミズモード！
            return 7637;
        case 5786:  // エタニティ ～深夜の濡恋ちゃんねる♡～
            return 7657;
        case 5758:  // 100万の命の上に俺は立っている
            return 7381;
        case 5764:  // 呪術廻戦
            return 7162;
        case 5763:  // 犬と猫どっちも飼ってると毎日たのしい
            return 7192;
        case 5762:  // 魔女の旅々
            return 7050;
        case 5780:  // ラブライブ！虹ヶ咲学園スクールアイドル同好会
            return 7204;
        case 5774:  // おそ松さん (第3期)
            return 7588;
        case 5633:  // ギャルと恐竜
            return 6936;
        case 5823:  // シルバニアファミリー ミニストーリー ピオニー
            return 7730;
        case 5751:  // ダンジョンに出会いを求めるのは間違っているだろうか III
            return 6964;
        case 5768:  // 池袋ウエストゲートパーク
            return 6935;
        case 5796:  // One Room サードシーズン
            return 7382;
        case 5920:  // 劇場版 BEM ～BECOME HUMAN～
            return 7542;
        case 5811:  // それだけがネック
            return 7683;
        case 5795:  // 体操ザムライ
            return 7644;
        case 5793:  // 土下座で頼んでみた
            return 7626;
        case 5821:  // テイルズ オブ クレストリア―咎我ヲ背負いて彼は発つ―
            return 7659;
        case 5752:  // トニカクカワイイ
            return 7379;
        case 5814:  // どうしても干支にはいりたい2
            return 7698;
        case 5766:  // 無能なナナ
            return 7473;
        case 5828:  // カオルの大切なモノ
            return 7759;
        case 5760:  // いわかける！ -Sport Climbing Girls-
            return 7492;
        case 5785:  // 大人にゃ恋の仕方がわからねぇ！
            return 7656;
        case 5767:  // まえせつ！
            return 6811;
        case 5749:  // おちこぼれフルーツタルト
            return 6593;
        case 5773:  // 魔王城でおやすみ
            return 6950;
        case 5788:  // ツキウタ。THE ANIMATION2
            return 6333;
        case 5862:  // アーヤと魔女 (TV先行版)
            return 7592;
        case 5787:  // レヱル・ロマネスク
            return 7479;
        case 5808:  // ぐらぶるっ！
            return 7425;
        case 5798:  // A3! SEASON AUTUMN & WINTER
            return 6914;
        case 5772:  // かいじゅうステップ ワンダバダ 第2シリーズ
            return 7490;

        // 2020年冬
        case 5541:  // 映像研には手を出すな！
            return 6665;
        case 5548:  // ドロヘドロ
            return 6335;
        case 5521:  // 痛いのは嫌なので防御力に極振りしたいと思います。
            return 6399;
        case 5530:  // プランダラ
            return 6609;
        case 5542:  // 群れなせ！シートン学園
            return 6987;
        case 5518:  // ID:INVADED イド:インヴェイデッド
            return 6794;
        case 5512:  // おーばーふろぉ
            return 7157;
        case 5726:  // りばあす
            return 7165;
        case 5535:  // ランウェイで笑って
            return 6946;
        case 5544:  // はてな☆イリュージョン
            return 7197;
        case 5594:  // 大家さんと僕
            return 7338;
        case 5552:  // 推しが武道館いってくれたら死ぬ
            return 6059;
        case 5543:  // うちタマ?! ～うちのタマ知りませんか？～
            return 6748;
        case 5558:  // ハイキュー!! TO THE TOP 第1クール
            return 6408;
        case 5531:  // 理系が恋に落ちたので証明してみた。
            return 6438;
        case 5577:  // パウ・パトロール (シーズン2)
            return 7261;
        case 5556:  // 空挺ドラゴンズ
            return 6620;
        case 5540:  // 22/7
            return 6813;
        case 5519:  // pet -ペット-
            return 5815;
        case 5532:  // ぼくのとなりに暗黒破壊神がいます。
            return 6255;
        case 5517:  // ゆるキャン△ ショートアニメ「へやキャン△」
            return 6293;
        case 5523:  // インフィニット・デンドログラム
            return 6468;
        case 5527:  // とある科学の超電磁砲T
            return 6301;
        case 5516:  // マギアレコード 魔法少女まどか☆マギカ外伝
            return 6244;
        case 5537:  // 異世界かるてっと2
            return 6773;
        case 5538:  // BanG Dream! 3rd Season
            return 6039;
        case 5551:  // ソマリと森の神様
            return 6605;
        case 5528:  // 八十亀ちゃんかんさつにっき 2さつめ
            return 6765;
        case 5515:  // ダーウィンズゲーム
            return 6328;
        case 5574:  // へんたつ
            return 7239;
        case 5575:  // ヒーリングっど♥プリキュア
            return 7164;
        case 5534:  // 異種族レビュアーズ
            return 6775;
        case 5560:  // Re:ゼロから始める異世界生活 新編集版
            return 7187;
        case 5514:  // 恋する小惑星
            return 6508;
        case 5536:  // 虚構推理
            return 6462;
        case 5522:  // ネコぱら
            return 6785;
        case 5520:  // 魔術士オーフェンはぐれ旅
            return 6422;
        case 5545:  // 地縛少年花子くん
            return 6615;
        case 5524:  // 宝石商リチャード氏の謎鑑定
            return 6875;
        case 5899:  // 7SEEDS 第2期
            return 7053;
        case 5411:  // ゼノンザード THE ANIMATION
            return 7329;
        case 5526:  // SHOW BY ROCK!! ましゅまいれっしゅ!!
            return 7163;
        case 5525:  // number24
            return 6599;
        case 5533:  // 織田シナモン信長
            return 6815;
        case 6010:  // 映画 ねこねこ日本史 ～龍馬のはちゃめちゃタイムトラベルぜよ！～
            return 6967;
        case 5554:  // ブレーカーズ
            return 7198;
        case 5568:  // まるまるマヌル
            return 7211;
        case 5597:  // 忍たま乱太郎の宇宙大冒険 with コズミックフロント☆NEXT 第5シーズン
            return 7370;
        case 5818:  // 虫籠のカガステル
            return 6340;
        case 5572:  // なつなぐ！
            return 7128;
        case 5579:  // 砂ノ灯
            return 7263;
        case 5539:  // ARP Backstage Pass
            return 6771;
        case 5738:  // ゴブリンスレイヤー -GOBLIN’S CROWN-
            return 6601;
        case 5550:  // どるふろ -狂乱篇-
            return 7216;
        case 5529:  // フライングベイビーズ・プチ
            return 7217;

        // 2021年春
        case 5928:  // 幼なじみが絶対に負けないラブコメ
            return 7712;
        case 5938:  // 美少年探偵団
            return 7757;
        case 5937:  // 赤ちゃん本部長
            return 8019;
        case 5929:  // ゾンビランドサガ リベンジ
            return 6817;
        case 5936:  // 恋と呼ぶには気持ち悪い
            return 7269;
        case 5959:  // やくならマグカップも
            return 7639;
        case 5955:  // 不滅のあなたへ
            return 7252;
        case 5974:  // バトルアスリーテス大運動会 ReSTART!
            return 7660;
        case 5644:  // キングダム 第3シリーズ
            return 7087;
        case 5956:  // ダイナ荘びより
            return 7866;
        case 5931:  // ひげを剃る。そして女子高生を拾う。
            return 7227;
        case 6001:  // ヘタリア World★Stars (第7期)
            return 7754;
        case 5985:  // EDENS ZERO
            return 7544;
        case 5976:  // MARS RED
            return 7322;
        case 5948:  // 灼熱カバディ
            return 7605;
        case 5946:  // 戦闘員、派遣します！
            return 7392;
        case 5947:  // 僕のヒーローアカデミア (第5期)
            return 7419;
        case 5935:  // スライム倒して300年、知らないうちにレベルMAXになってました
            return 7047;
        case 5930:  // 異世界魔王と召喚少女の奴隷魔術Ω
            return 7474;
        case 5991:  // すばらしきこのせかい The Animation
            return 7585;
        case 5940:  // 憂国のモリアーティ 2クール目
            return 7709;
        case 5939:  // 東京リベンジャーズ
            return 7603;
        case 5980:  // 擾乱 THE PRINCESS OF SNOW AND BLOOD
            return 7995;
        case 5932:  // ましろのおと
            return 7624;
        case 5933:  // 聖女の魔力は万能です
            return 7672;
        case 5971:  // シャドーハウス
            return 7707;
        case 6018:  // えとたま ~猫客万来~
            return 8002;
        case 5945:  // 究極進化したフルダイブRPGが現実よりもクソゲーだったら
            return 7837;
        case 5954:  // カードファイト!! ヴァンガード overDress
            return 7899;
        case 5984:  // セブンナイツ レボリューション -英雄の継承者-
            return 7930;
        case 5958:  // マジカパーティ
            return 7977;
        case 5967:  // BLUE REFLECTION RAY/澪
            return 7997;
        case 5957:  // デュエル・マスターズ キング！
            return 7990;
        case 5951:  // もっと！まじめにふまじめ かいけつゾロリ 第2シリーズ
            return 7736;
        case 5962:  // 大家さんと僕 シーズン3
            return 8020;
        case 5997:  // 魔入りました！入間くん 第2シリーズ
            return 7374;
        case 5973:  // 86―エイティシックス―
            return 7393;
        case 5934:  // 転生したらスライムだった件 転スラ日記
            return 7398;
        case 6006:  // ネコこのゴロ 令和版
            return 8335;
        case 5990:  // バクテン!!
            return 7745;
        case 5923:  // 新幹線変形ロボ シンカリオンZ THE ANIMATION
            return 7892;
        case 5993:  // セスタス -The Roman Fighter-
            return 7741;
        case 5970:  // どすこい すしずもう
            return 7634;
        case 5965:  // イジらないで、長瀞さん
            return 7584;
        case 5949:  // オッドタクシー
            return 7920;
        case 5982:  // Vivy -Fluorite Eye's Song-
            return 7921;
        case 5922:  // Thunderbolt Fantasy 東離劍遊紀 3
            return 7984;
        case 5964:  // おしりたんてい (第5シリーズ)
            return 8021;
        case 5966:  // さよなら私のクラマー
            return 7677;
        case 5969:  // レゴ モンキーキッド
            return 7989;
        case 5944:  // ドラゴン、家を買う。
            return 7003;
        case 5917:  // 黒ギャルになったから親友としてみた。
            return 7970;
        case 5987:  // あはれ！名作くん (第6期)
            return 8145;
        case 6004:  // ミュークルドリーミー みっくす！
            return 7810;
        case 5950:  // SHAMAN KING
            return 7546;
        case 5981:  // わしも-wasimo-(第9シリーズ)
            return 8089;
        case 5992:  // 結城友奈は勇者である ちゅるっと！
            return 7912;
        case 6011:  // 猫ジョッキー
            return 8409;
        case 5942:  // フルーツバスケット The Final
            return 7690;
        case 5963:  // ゴジラ S.P <シンギュラポイント>
            return 7708;
        case 5996:  // 妖怪ウォッチ♪
            return 7996;
        case 5989:  // NOMAD メガロボクス2
            return 7913;
        case 6019:  // レゴ フレンズ シーズン2
            return 8552;
        case 5961:  // 宇宙なんちゃら こてつくん
            return 7688;
        case 6005:  // いたずらぐまのグル～ミ～
            return 7998;
        case 5986:  // SDガンダムワールド ヒーローズ
            return 7815;
        case 5968:  // Fairy蘭丸～あなたの心お助けします～
            return 7918;
        case 5960:  // iiiあいすくりん
            return 7936;
        case 6016:  // ミニドラ (小林さんちのメイドラゴン)
            return 8313;
        case 5943:  // スーパーカブ
            return 7154;
        case 5953:  // SSSS.DYNAZENON
            return 7199;

        default:
            return std::nullopt;
        }
    }
}
