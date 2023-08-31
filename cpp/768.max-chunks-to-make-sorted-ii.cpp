/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
 *
 * algorithms
 * Hard (48.69%)
 * Likes:    462
 * Dislikes: 20
 * Total Accepted:    22.6K
 * Total Submissions: 46K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * This question is the same as "Max Chunks to Make Sorted" except the integers
 * of the given array are not necessarily distinct, the input array could be up
 * to length 2000, and the elements could be up to 10**8.
 * 
 * 
 * 
 * Given an array arr of integers (not necessarily distinct), we split the
 * array into some number of "chunks" (partitions), and individually sort each
 * chunk.  After concatenating them, the result equals the sorted array.
 * 
 * What is the most number of chunks we could have made?
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [5,4,3,2,1]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2,
 * 3], which isn't sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,1,3,4,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [2, 1], [3, 4, 4].
 * However, splitting into [2, 1], [3], [4], [4] is the highest number of
 * chunks possible.
 * 
 * 
 * Note:
 * 
 * 
 * arr will have length in range [1, 2000].
 * arr[i] will be an integer in range [0, 10**8].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> data(arr.begin(), arr.end());
        sort(data.begin(), data.end());
        long long a=0, b=0;
        int res = 0;
        for(int i=0; i<arr.size(); ++i)
        {
            a += arr[i];
            b += data[i];
            if(a==b)
            {
                res++;
                a=b=0;
            }
        }
        return res;
    }
};
// @lc code=end
// [34489256,60542123,33793018,229508,54980535,14053731,23671563,11258610,48338814,12822964,26840404,93524250,82734288,96379105,66723189,37898009,67082747,82623536,21616936,9601095,9256743,48165620,18680512,7845237,10251231,29181864,88978596,74972398,31955674,68364211,1427003,33667404,62590095,32045737,36773828,55861437,88010247,98717917,84818771,50745281,67870464,82606562,68529901,40430671,54642194,71342964,31608047,46924048,64688538,70337926,13437274,94817371,68696354,70783776,10361604,5657591,56229665,51706646,60920818,60057394,37251927,76279876,15429389,93859695,56678721,15706032,5318942,53284662,78080290,54107758,48230642,65633895,6169194,31003041,22637767,68209159,4350125,61818933,7312086,76395438,18946806,9367794,42480502,19510663,63549487,98501763,76690325,4240337,5646192,92326579,65887216,57019698,57604597,47482747,67273767,17318026,29873550,80920234,22735988,85363304,75129518,69169231,84495100,10409471,56908669,12067038,45792483,43576728,23900318,36968207,9742429,74229887,25272254,79803617,89755509,16744996,31094679,8033925,37399997,54066378,78565678,12865213,47870989,89645861,6576041,18794172,81501522,98146761,66299567,81707853,67052754,2129201,83055124,41374334,32555038,13168755,50610899,69078483,31753902,9427081,86240955,71282236,4078231,51322271,90687418,47589089,90982347,80860025,12595203,10408710,38666244,97672984,1672107,29203749,47589943,63075290,96161959,7342435,69030083,46078767,65248316,80452462,24221459,76496706,48544038,37926233,81858324,55294724,65231515,3884432,90603319,1496071,68831810,48706350,45605107,24949579,34702557,18698155,64719055,8670991,56687505,68432122,27350857,51109540,56923039,14829757,82799688,51945529,54178242,64711401,22328409,56702103,49169925,11757057,57853897,41987698,68954667,9582919,55396847,64350945,54365682,78945134,13539229,10541055,58272593,16866443,57158642,11267050,26993653,38723238,30555306,52891878,27061392,12008462,24043049,29604156,7036760,6461102,94155070,35326322,30854963,32562994,95570825,65770280,83691764,58732109,41589226,83882047,72198512,12370486,93363616,12583390,32296663,88049606,57111463,84735766,8011757,74466742,26666486,12955975,98656101,16750146,29236042,63580448,3256466,19398922,12031452,71487575,97317310,27058100,35780057,40860244,73292500,3349130,94252775,2535767,92809923,64017537,9917125,19438604,83895698,50706437,3493450,36691827,63915560,79838048,62983834,80483093,64454800,25828056,19864538,74952464,59165928,74199859,65912161,94333790,2820625,49918238,42997064,44146449,89119631,50574400,71603970,95660403,72659946,32936671,70774481,22673591,5366199,16287027,22309802,52218321,74420998,13479790,37058439,85537983,27757469,96637560,5029061,87429436,67134463,81073579,40774048,65749417,32591430,29759902,62151644,92211925,79338973,56440970,20068352,5247233,28256529,67739142,38168681,41463455,67027926,34012127,23794337,37937034,42516708,12424885,42132083,68361393,49741103,79488577,36906550,62258463,86461939,879220,37066166,23850277,80098508,21794405,38664814,71259880,64897444,16606668,41139810,49502541,19405946,3115816,34178279,35786617,99082660,72338428,35549923,32500086,55236278,73369303,47955754,9599629,32507362,82567646,68425311,55367208,3606446,56903612,18867940,64883207,59091588,57535840,30949086,80369840,14744005,29888761,37835689,59127288,52576002,88383621,43523558,71504556,51057115,90863813,13572456,15103893,16837980,28139460,83271793,89537319,39621226,67922928,56528581,34279243,43530511,82888838,95756494,11653549,13698950,38983395,19561584,68209907,22554049,72525501,39369079,27779447,40942275,98376166,8369590,53166242,37568243,74514521,41073954,24928338,28593973,71032184,72179344,97212978,57280521,21166373,80374765,88680701,52580741,50947638,36002880,57042107,94633289,26849164,28847020,6176018,52620560,43269375,30913107,11112996,78449062,50922696,62321900,67958139,60459423,58627978,40374614,6764859,87609477,86606200,92710919,97925402,54865455,96245176,35697367,88855465,6840979,97727355,73063444,38137341,70902028,90130598,61788691,90121727,48645585,98026452,84657449,2159707,66407393,39602216,38027595,64426407,88296839,60857894,81969668,4577649,79652207,84903828,8124918,92522253,25311452,57854877,53518648,18214792,64491997,73621094,28824244,865632,76343145,58980767,44845216,62350253,67267868,56692146,20869782,62896749,25778846,86764897,86104145,23007304,47184774,28749706,98800729,88539870,34696986,11574354,12026471,30422830,95005541,77481704,57860361,51355093,45558044,79515883,97462460,40523909,42272249,92333657,69211975,56631562,19740306,24376859,65292666,2249918,86080751,35696391,93543724,68308808,86762166,27641541,22002340,23286583,14531582,58422884,39744470,27703712,33831334,64369814,23637976,40527903,57804546,78714386,60927177,25162921,12285917,18480630,54353198,52029701,32366223,60638866,81337596,60418098,76576129,41033547,22615107,63397995,43663790,77450617,92379755,74075214,54096683,26035079,56946345,42700721,37624356,31940807,885643,16744636,88512994,65977557,52079425,90070964,8930607,41766047,16648099,56612655,21353666,64374727,56981317,36011563,43419983,75097914,15283007,34606809,80618188,79627325,35614962,10818919,50222061,35520811,15359980,36498533,57331202,29992491,64356165,7330361,69107018,96250823,97770114,96731914,98146983,50204468,95020497,47482949,92270249,66252037,6724865,5945747,8966504,35523585,36228675,48370157,2968612,9062351,13255342,62335956,95724730,29941081,60944335,88160945,73589218,7845982,46164363,47162603,43532906,58064791,36445022,7577409,64323951,33102528,8282337,74862138,9406203,83550422,34925780,23723765,71808115,84593231,64341010,92763171,62067136,10247156,35775052,9771565,67114463,34417633,5258588,22264622,49216145,93808346,3475871,35161431,71472011,57082396,12910707,70510377,63975397,33943892,10990628,87139033,132708,42892447,43266583,69614057,97744837,53865149,64921146,40859029,91955395,36243444,71191013,56506660,71413165,39927785,90467131,90647150,72285141,75423097,14806770,16591910,1515071,83717041,950845,83860729,51543350,63179535,52311835,66400161,36987497,15432003,43742501,72632385,91085043,91303308,45594420,15908716,66127233,46140418,1482509,88532667,46413113,44962373,25413203,64887388,1694880,3306118,16233833,79171150,83164267,51475462,17016338,55625225,81059876,78577194,49225751,50224902,17521541,3572917,96151282,843104,15605705,24643841,75222616,43694639,97230218,74086504,43636043,91589318,29848434,33431492,28446779,58488080,64487947,5346189,3088985,35342561,36509215,87705220,36485929,80610889,36109239,93847489,55439714,66381864,29858555,43453848,14832749,91182558,88913914,4404676,14104019,55425291,10987535,40291579,44732024,68721917,39204656,44078170,26295092,83355428,53603641,56032023,77326721,6783987,17613932,26395666,34804040,66728093,21831808,68981799,70950921,8605798,34462867,23175224,69874039,17173635,47412757,59457226,55434353,67098710,68099004,37750798,40039865,34428685,93486620,51926484,8316751,77555161,23601621,41621691,40499383,71669666,17322062,13505135,19773463,58289435,77899809,32298875,62589599,99214079,7621518,47570364,86075043,13786880,1166256,283666,23118923,62230005,44057705,91411330,34147576,83251586,90922408,3467204,86052703,10477586,10203054,3489899,83466676,9971571,66148229,73261610,18435323,45931053,69340168,7896239,7325149,17133347,86079029,68884628,64485985,3285872,90442617,83781879,29644271,41423795,52432869,91034565,60752740,94667660,99424512,14061414,99858528,37599966,77677125,27775093,81107537,56425869,32851392,98000832,88819934,40276538,10758413,89447755,79197556,91310632,43321224,43174052,6458545,40027088,92539461,93939502,93971418,26899512,75539265,63151933,12808838,52217063,25379712,58872457,19380683,20007171,82926797,11850854,83401790,75294978,34365801,83049473,52486511,4933816,50574856,43651153,70674140,80288177,69123008,99680665,67951880,54546321,90355952,93306671,89347974,8227993,18345817,81075252,71837686,53828381,36084804,3906713,29318327,36844956,28525852,77344913,35100996,63561127,88779267,16749560,51829982,29397252,43188020,84125752,43775183,23520178,99062975,10099538,72132914,30923382,6632962,7701854,89425054,85101767,54312412,48626083,20234797,58939768,94393021,17433560,82034795,79870854,46905056,44381177,37857231,3636471,50732707,22586136,61269718,36932948,60543449,94701389,30348226,69718386,61894364,91121268,89727923,53542437,128333,17310201,86877002,41304795,51656735,58654351,51234800,77153918,29814671,61134444,16713284,20679054,19775174,15212752,84400808,74085260,94104215,37608895,61829686,81150986,83803781,92276470,97787850,35138609,18921536,57297143,8886686,75373340,34395049,81260640,62209890,87705725,3462755,52621081,50400070,90404048,80153394,6764874,71764810,45762303,89834911,52944153,20830319,33365801,33255868,38144398,455479,14369758,47004401,836118,47054143,76923969,1759548,89362159,92895762,58940273,52273654,82405412,91439180,3736430,22646031,60440618,45013398,35938686,41961492,99708519,53239457,94787714,71068236,88772143,47492522,94226528,84160158,98001379,51112754,21020309,30005075,83163817,36692808,22853999,11830630,74735581,52613725,95348305,38597499,80842668,90522498,65370745,60711513,83787,53159112,80859281,59812107,83725353,22255582,15653161,12383066,89367339,77933798,60130507,56982682,74430693,59566875,82522175,95775852,62582148,37354762,13399305,90629603,56964000,86401443,95011746,97987382,78002825,13545167,63707473,80960914,83500989,23508114,86992663,60826344,38952353,95628080,37614195,52821827,64247852,44972192,28743183,7668856,82957156,57816440,44383460,30189594,81593662,28116023,60574484,48118266,27273831,42369948,14423872,34752548,88000668,78256081,41264386,63645759,67569527,65567202,12187949,49993389,47632489,1810090,96578110,20020796,66310778,25277458,50123930,52674261,68475566,95671568,52490757,75644066,49861438,44621082,44691361,94048537,72810236,91703822,64530881,36026106,33920535,1777428,58016818,83405964,58584473,16442762,39979862,96384089,7789813,59790553,1974316,94904228,34422455,36131380,2017738,48901671,79520806,1079787,41107489,39669547,4373539,71133293,43058927,87170099,24990456,9105317,75379986,59555504,7324403,64136474,21150924,22201052,95244259,86373643,77318788,17395432,49828148,46043072,79352445,68475847,58385396,2575728,94107930,40137818,16619762,11455973,71894644,86688732,5205538,63493150,21095161,60694834,22577777,6489860,99767891,23221958,57677102,56350320,61304777,35869384,16068807,91036833,18377277,63758549,71058707,1330699,84026070,88647829,55421630,74956641,74619072,19707079,33276367,51296929,52600923,76855286,63953983,35142575,79855349,74399674,52078851,96332925,67113951,56318000,23430842,3645148,79718663,36660901,38808497,73056126,44213116,68012749,71871495,51110925,30454976,3905932,18754262,92591716,32878819,67898021,55923043,75283332,90965982,71831068,82017280,45059286,76476118,35544959,62461624,37609542,38970956,4240736,92120408,66710892,90691362,65300917,54491651,49132869,73939275,720765,37797770,57114914,88798077,92876819,74094910,82786381,40498057,64204380,6924076,97729678,69545258,14617651,91616835,996222,51623648,74217549,21152924,61710221,28306109,99824723,71452873,71421383,73354640,4803447,19957548,72637876,57387311,52068953,48543454,83092689,64639597,65948078,91133467,59378390,43152379,25827366,68436672,63203339,45637817,75895844,47417698,50837722,51678250,42846945,1369984,50317491,1862403,37129050,83923135,33114055,82726475,80282161,7965945,13162973,66725377,57622636,74145171,78727967,56108665,71611673,48760724,16499129,10841864,8377751,84219226,41435148,32836888,62842684,94793788,71482616,72173199,87691384,26107495,92310615,76576707,41819235,25227657,51994443,30128432,9251946,10574633,66231518,97572057,82555094,43917318,31751632,15404950,58624465,82831259,26616424,84645011,61320589,99672810,7058980,52096179,92778466,94372845,28356530,16989693,49609930,77740824,60468645,97848044,63200849,26259533,98914710,74364196,26210160,28224754,32488631,55025574,99232530,74602576,94822897,2745874,15700437,52720662,37863082,16752158,19891445,51817043,98709012,8317344,56734755,19824350,80477575,23428412,69538810,95343000,63146096,94132251,61414443,78081087,56477124,39420106,91411074,26537083,44543290,41045497,9062532,18664257,64291014,55122819,74679024,98008593,86295481,93354366,94030244,76614803,86804093,98559141,31133750,39841515,92640767,23082739,90604965,72622381,6539168,12167110,52748714,18082386,83238151,83116335,26025604,8642699,37122524,25411694,94515083,78241252,69492403,70078083,21934263,32388493,12014435,70511221,53810197,55085275,18842556,10780157,64782721,38744486,84305944,86233846,99807503,66507634,70108102,11086259,21194855,26506097,49229851,83632925,53417478,97312936,58682543,56124434,5883055,44486943,9006661,82526178,54574424,71409746,43999927,60593776,85209104,28308860,84319190,16753079,74604585,72740440,82646144,70146519,490565,22425268,92257972,12295174,67033505,73452545,93803008,49664203,12569064,9123304,3909972,18453457,35867093,4284536,29757588,75670950,86498811,92134095,79942843,45548089,92864821,20044846,54980931,97335540,30420597,87701239,30506494,530377,19640227,28905856,41710978,18753411,30405601,71816274,36567663,46431310,11087319,44767841,29160298,20351525,47514713,56710942,42229648,20349803,91136401,21492830,60250084,91223709,40198631,54661710,58187027,44720873,49459034,61284903,62879432,64726986,11509378,48562203,21450331,96111359,78882104,78924831,80407797,66472382,47464685,6355112,95514197,28495960,49897165,22100510,75284126,68368578,8526146,31966988,82429832,39747356,49303454,99908486,94274253,49940258,25808769,1363497,7373751,52672138,33514928,87982518,42291715,27039816,26285431,28480629,2465290,59835980,91333183,91480500,84990889,46852250,55811641,90850916,82708238,77498334,39150845,88490518,41148838,77729913,60442819,48605514,60291174,78816714,12278020,78269987,70823868,50009885,72903943,59891799,57624364,98922667,60746253,54716809,97516362,83799847,15672520,62278496,97244256,95462403,70772251,56854925,47909564,90482006,91306609,45023127,20177813,64192463,16724334,25769851,1221924,33589167,45783315,44385553,62292719,44954065,58302970,135928,96674040,1393574,83329069,89277953,40435868,89120159,94949283,87799369,66048465,35190633,79902857,95292353,45255006,11429553,23691085,76780438,16775915,58123078,79030947,43477009,97967301,5844613,49834250,45711164,7879593,44776711,32041090,44408677,58310431,96171331,28895937,81661448,61699286,60145638,71042481,97202985,18795886,76535703,57512158,33897972,82464841,99341487,48917281,3989335,70812878,57589979,66416418,38841183,6310071,53842482,41783961,59241090,45284734,50517624,79432121,55775756,63825812,49895763,3348663,76600969,63742336,21053417,13320616,39694019,86269280,34710006,23405837,72046538,39506365,95655487,73461525,82360567,90780589,18312393,87521013,74512843,26338866,98863861,97991270,67502475,16121553,92376235,55862118,69257468,87527217,88578072,13882650,92629654,95700047,51665954,91865532,11884951,73996789,87434990,9575736,29517697,49722582,73242072,44431057,72838392,91723978,6070806,92016483,46282553,1997222,11076590,74946306,96559927,3870940,82797545,2459124,65001408,22738627,52129007,3122443,99633322,41124504,8450284,27316222,62298749,46207228,82504265,58348638,853907,28208577,46800073,90378069,55811126,30908450,99665972,45371443,52905986,47954851,90243594,99599748,47130950,52335371,98053798,76962183,19563160,33689410,48753319,308097,14448645,3476987,25331358,13834065,81385815,68010199,57110421,88151385,45456999,74425472,63881956,89325640,89809372,69834507,12340587,31237243,89185914,79198549,9607852,49926856,71636742,94870618,44089770,55050994,68215906,87594,17566601,71252093,36905728,12775777,47300375,5154256,63962007,15170655,58881955,67398846,48022002,38458809,8766904,51680789,56456799,81692197,70646789,27016661,57981586,46604429,84256379,34163946,59458580,48680667,77838290,38938569,70778928,67817835,20906883,79502416,90711590,53512617,24285957,90209591,11341065,5129056,17069657,42322328,59063528,3639310,8368620,6748237,23576484,10326032,27908066,66403055,34991400,93639870,51138847,18053138,81988046,14881906,23332636,58519991,16317670,84850012,28569975,27672240,42903799,67019869,76130215,77812786,95043931,48088599,10642499,19108311,37773835,89251800,61611397,83652247,6809965,29223759,93263259,43011865,65639212,14290112,66004342,84400469,50046191,20110441,7197506,53041442,71874810,91478650,57249372,26286209,5212451,43912873,9355699,92622927,98023720,75564126,75738463,85319687,53798444,13559652,16890108,32918630,40562249,27943108,12457962,52703991,22260097,40504907,79808042,13921579,93354687,68725189,9983708,39623744,85187367,10168487,55892923,97274890,99770492,61948745,76127125,58095733,5057428,92041469,20911762,76028393,33673952,76770500,79787513,57363248,55804504,32428589,13104659,34075634,48222245,23219709,32792692,47150221,59181763,82416921,25043917,9096117,85051812,57080877,74618416,56265143,4660872,52213025,82371145,55603434,8668379,20389291,5179927,11158319,98259431,8074830,37818959,57745100,2273667,92495490,5853676,15237457,36277236,64641756,92920661,19111658,12854830,67375151,7387780,97970456,54889597,62235350,86747509,45845022,32044431,35009394,14417392,59774351,78577047,93955972,1670630,47964749,98052290,9023392,83288686,9029173,16983464,27596226,73211794,32092745,97022794,98483899,61069069,91343125,17316088,34970806,57057652,19307532,12646297,26918969,28987370,43185697,81612541,65285597,74085347,53761151,30997513,66234123,2375829,9199555,18883753,33016871,12740571,58722385,60796813,35588968,44991181,60874606,40021495,35768706,93425023,48927071,62690393,763327,95661246,51633908,81362279,6691239,14244030,75678376,90427658,85271510,17754486,71978000,83912724,29893969,13431146,51483927,53033400,69706166,68831289,92276451,45816237,50464139,43681759,49291084,3556229,66629886,58869906,6201088,75774200,761814,52594104,95975205,32679576,1584143,72291971,67856637,23587352,93744007,7925406,28420475,47730586,44953050,49910332]
