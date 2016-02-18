#include <stdio.h> /* For NULL... */

const char *firmware[]={
	":201E000012010002FFFFFF40FFFF48200100010200010A060002FFFFFF4001000902190091",
	":151E200001010080320904000001FFFFFF00070582010014014A",
	":191E36000902190001010080320904000001FFFFFF0007058201400001E0",
	":201E5000040309040E0373006900670072006F006B0010036600780032006C006100660068",
	":041E700077000000F7",
	":040000000201B9320E",
	":01000B0032C2",
	":0100130032BA",
	":01001B0032B2",
	":0100230032AA",
	":01002B0032A2",
	":01003300329A",
	":01003B003292",
	":01004300328A",
	":01004B003282",
	":01005300327A",
	":01005B003272",
	":01006300326A",
	":03006B0002038607",
	":030073000203ADD8",
	":03007B000207D1A8",
	":03008300020F1158",
	":03008B000203CE9F",
	":0300930002041D47",
	":03009B000207CE8B",
	":0300A300020F3D0C",
	":0300AB00020F3E03",
	":0300B300020F3FFA",
	":0300BB00020F42EF",
	":0300C300020F1316",
	":0300CB00020F2FF2",
	":0300D300020F30E9",
	":0300DB00020F32DF",
	":0300E300020B2CE1",
	":0300EB00020FBB46",
	":0300F3000207CF32",
	":0300FB000207D029",
	":03010300020B2BC1",
	":03010B00020B2DB7",
	":03011300020B2EAE",
	":03011B00020F9E32",
	":03012300020F3B8D",
	":03012B00020F4080",
	":03013300020F4375",
	":03013B00020F456B",
	":03014300020F3C6C",
	":03014B00020F415F",
	":03015300020F4454",
	":03015B00020F464A",
	":03016300020F9DEB",
	":03016B00020F334D",
	":03017300020F3543",
	":03017B00020F3739",
	":03018300020F392F",
	":03018B00020F342C",
	":03019300020F3622",
	":03019B00020F3818",
	":0301A300020F3A0E",
	":0301AB00020F310F",
	":0301B300020F1226",
	":030224000201B61E",
	":0301B6000204FF41",
	":2002270090E61274D8F00000000090E611E0FF747F5FF00000000090E610E0FF747F5FF0A4",
	":200247000000000090E613E0FF747F5FF00000000090E614E0FF747F5FF00000000090E6CC",
	":2002670015E0FF747F5FF00000000090E6047480F00000000090E6047402F0000000009073",
	":20028700E604E4F00000000090E6187408F00000000090E6207404F00000000090E621E426",
	":2002A700F00000000090E6407403F00000000090E6D27402F0000000002290E7407401F03E",
	":2002C70090E74175F000120F1490E68AE4F090E68B7402F02290E60AE090E740F090E68A61",
	":2002E700E4F090E68B04F022AF82BFB0028015BFB1028005BFB21B80128F1090E68BE4F04C",
	":20030700758201221202C1758201221202DC7582012275820022E582FF600475820022AD1A",
	":2003270022AE23AF248D828E838FF0E4120F1475820122E582FF7004E522600475820022C0",
	":2003470090E6837412F0E0FF74204FF090E6047480F00000000090E6047402F00000000037",
	":2003670090E604E4F0000000007582012275820122AF82BF01047F0180027F008F8222C08B",
	":20038700E0C082C083C007C0D075D000D200AF9174EF5FF59190E65D7401F0D0D0D007D07C",
	":2003A70083D082D0E032C0E0C082C083C0D075D008AF9174EF5FF59190E65D7402F0D0D01C",
	":2003C700D083D082D0E032C021C0E0C0F0C082C083C007C006C005C004C003C002C001C0BD",
	":2003E70000C0D075D000758200120DFDAF9174EF5FF59190E65D7410F0D0D0D000D001D02E",
	":2004070002D003D004D005D006D007D083D082D0F0D0E0D02132C021C0E0C0F0C082C083BC",
	":20042700C007C006C005C004C003C002C001C000C0D075D000758201120DFDAF9174EF5FAE",
	":20044700F59190E65D7420F0D0D0D000D001D002D003D004D005D006D007D083D082D0F017",
	":20046700D0E0D0213290E60B7403F0C20075100090E680E0FF740A4FF09005DC120F479078",
	":20048700E680E0FF74F75FF090E600E0FF74E75F4410F0E500D2E890E668E0FF74084FF0EC",
	":2004A70090E65CE0FF74014FF0E0FF74024FF0E0FF74204FF0E0FF74104FF0D2AF1202272C",
	":2004C700020594300005120B2FC200E510602674B1B5101E90E6A0E0FF20E11990E68BE0C4",
	":2004E700FFBF030990E74075F000120653751000800375100002079312046C1204CA80FB9E",
	":2005070075AF03759AE4759B007E007F0090E67BE4F00EBE00010FC3EE9480EF6480948060",
	":2005270040EB2290E6F3E4F090E6C3F090E6C1F090E6C2F090E6C074E4F090E6F4E4F09066",
	":20054700E6D3F02290E67174FFF0F5B490E672E0FF74804FF043B6800000000090E6C5E444",
	":20056700F00000000090E6C4E4F02290E6C6E4F090E6C7F090E6C8F090E6C9F090E6CAF08A",
	":2005870090E6CBF090E6CCF090E6CDF02290E60174EEF090E6F574FFF012052A1205071294",
	":2005A700054B120572C2012285822385832485F025AD23AE24AF258D828E838FF0E5221258",
	":2005C7000F1474082DFAE43EFB8F048A828B838CF0E4120F1474102DFAE43EFB8F048A8288",
	":2005E7008B838CF0E4120F1474182DFDE43EFE8D828E838FF0E4020F1485822285832385FA",
	":20060700F024AD22AE23AF248D828E838FF07438120F1474082DFAE43EFB8F048A828B835F",
	":200627008CF07403120F1474102DFAE43EFB8F048A828B838CF0E4120F1474182DFDE43EA9",
	":20064700FE8D828E838FF07436020F1485821185831285F013E5BB30E7FB85118285128389",
	":200667008513F0120F9FFC30E50890E6187409F0800690E6187408F00000000085118285FA",
	":2006870012838513F0120F9FFC30E60890E60174EEF0800690E60174AEF074012511FAE4FB",
	":2006A7003512FBAC138A828B838CF0120F9FF9701674022511F8E43512FEAF1388828E83B3",
	":2006C7008FF0120F9F6005B906004002C3227D007EE4E4FFF514F5158A828B838CF0120FFD",
	":2006E7009FF87900C3E51498E515648089F063F08095F05045C002C003C0048D008E018F57",
	":20070700040DBD00010E752200888289838CF0C007C006C005C004C003C0021205AFD00299",
	":20072700D003D004D005D006D0070514E4B514020515D004D003D002809E8D168E178F1821",
	":2007470074022511FAE43512FBAC138A828B838CF0120F9FFC601674012DF516E43EF51764",
	":200767008F188C228D828E838FF01205AFAD16AE17AF188D828E838FF0120600900001120F",
	":2007870009F7758200120B14D201D322300137E5BB30E73290E6047480F00000000090E63D",
	":2007A70018E4F00000000090E6047402F00000000090E6187408F00000000090E604E4F01E",
	":0707C70000000000C2012246",
	":0107CE0032F8",
	":0107CF0032F7",
	":0107D00032F6",
	":0107D10032F5",
	":2007D20085822585832685F02790E601E0FC74FC5CF0E0FC74024CF090E6F574FFF0AA22DA",
	":2007F200AB23AC248A828B838CF0120F9F90E6F3F074012AF8E43BF98C07888289838FF0C3",
	":20081200120F9FF890E6C3F074022AFDE43BFE8C078D828E838FF0120F9F90E6C1F074039B",
	":200832002AFDE43BFE8C078D828E838FF0120F9F90E6C2F074052AFDE43BFE8C078D828E5B",
	":20085200838FF0120F9F90E6C0F074062AFAE43BFB8A828B838CF0120F9FFA90E6F4F075C7",
	":20087200AF07AD25AE268E078F9A7E008D9B759DE48E9E7F0090E67BE0FE90E67CF00FBF86",
	":20089200800040F190E67174FFF0F5B490E672E0FF74804FF043B6800000000090E6C4E411",
	":2008B200F00000000090E6C5E4F090E6C6F090E6C7F090E6C8F090E6C9F090E6CAF090E6CB",
	":2008D200CBF090E6CCF090E6CDF022AD82AE83AFF0E52275F009A4FC2DF9E43EFA8F038953",
	":2008F200828A838BF0120F9F90E6C6F07B0074012CF9E43BFAE92DF9EA3EF88F028982886F",
	":20091200838AF0120F9F90E6C7F074022CF9E43BFAE92DF9EA3EF88F02898288838AF012C5",
	":200932000F9F90E6C8F074032CF9E43BFAE92DF9EA3EF88F02898288838AF0120F9F90E68E",
	":20095200C9F074042CF9E43BFAE92DF9EA3EF88F02898288838AF0120F9F90E6CAF074055D",
	":200972002CF9E43BFAE92DF9EA3EF88F02898288838AF0120F9F90E6CBF074062CF9E43B28",
	":20099200FAE92DF9EA3EF88F02898288838AF0120F9F90E6CCF074072CFCE43BFBEC2DFD36",
	":2009B200EB3EFE8D828E838FF0120F9F90E6CDF022AC82AD83AEF0FF8E028F038B0190E62B",
	":2009D200CEE9F0000000007B0090E6CFEAF0000000007E008D0790E6D0EFF00000000090FD",
	":2009F200E6D1ECF022AE82AF838F0590E6D0EDF00000000090E6D1EEF02285822485832578",
	":200A120085F026E5BB30E7FB90E6F1E0FC7B008524828525838526F0EC120F14A3EB120FF6",
	":200A320014E52224FFFBE52334FFFC7A008A007900C3E89522E99523506EE5BB30E7FBEA5A",
	":200A520075F002A42524F8E52535F0F9AF26AEBD7D00888289838FF0ED120F14A3EE120FEA",
	":200A720014882789288F29888289838FF0120F9FFEA3120F9FFF8A017D00E9B50308EDB530",
	":200A92000404ADBF8002ADBE8D017D00E94206ED42078527828528838529F0EE120F14A3AF",
	":200AB200EF120F140A020A3F2285822485832585F0267C008C027B00C3EA9522EB952350BA",
	":200AD20040E5BB30E7FBEC75F002A42524F9E52535F0FAAB2689828A838BF0120F9FA312D7",
	":200AF2000F9FFFF890E6F0E8F089828A838BF0120F9FF9A3120F9F7A0090E6F1E9F00C800C",
	":190B1200B322AF82E5BB30E7FB74044FF5BB22AF82E5BB30E7FB8FBB222A",
	":010B2B003297",
	":010B2C003296",
	":010B2D003295",
	":010B2E003294",
	":0601E800E478FFF6D8FDEB",
	":12021200751A00751B00751C36751D1E751E1C751F1EE3",
	":200B2F0090E6B9E0FF24F45003020C2BEF240A83F582EF241083F583E47361772B8D2B2B82",
	":200B4F00A32BA9C0D80C0B0B0C0B0C0C0B0C0B0B0B0C120CA5E5826003020C4190E6A0E010",
	":200B6F00FF74014FF0020C41120D2EE5826003020C4190E6A0E0FF74014FF0020C41120DE7",
	":200B8F007CE5826003020C4190E6A0E0FF74014FF0020C41120E28020C41120374AF8290D8",
	":200BAF00E740EFF090E68AE4F090E68B04F0020C4190E6BAE0F582120378E582707490E633",
	":200BCF00A0E0FF74014FF0806990E6BCE0FF7522197523007524408F8212031DE582700B93",
	":200BEF0090E6A0E0FF74014FF0804790E740E519F090E68AE4F090E68B04F0803590E6BC21",
	":200C0F00E0FF90E6BAE0F5228F8212033AE582702190E6A0E0FF74014FF0801690E6B9E019",
	":200C2F00F5821202EFE582700990E6A0E0FF74014FF090E6A0E0FF74804FF022AF828F0692",
	":200C4F0053067FEE24F75003020CA1EE240A83F582EE240D83F583E4737A7E91A195A19922",
	":200C6F00A19D0C0C0C0C0C0C0C0C0C90E6A022EF30E7067EA27FE680047EA17FE68E828F4B",
	":200C8F00832290E6A32290E6A42290E6A52290E6A6229000002290E6B8E0FFBF8002801F0F",
	":200CAF00BF81028005BF826F803490E740E4F090E741F090E68AF090E68B7402F0805CE5AF",
	":200CCF001B25E0FFE51A420790E740EFF090E741E4F090E68AF090E68B7402F0803D90E6F2",
	":200CEF00BCE0F582120C4BAE82AF83EE4F7003F582228E828F83E0FE30E0047F0180027F29",
	":200D0F000090E740EFF090E741E4F090E68AF090E68B7402F0800475820022758201229004",
	":200D2F00E6B8E0FF6005BF0237801190E6BAE0FFBF0105751B0080317582002290E6BAE0FB",
	":200D4F00701A90E6BCE0F582120C4BAE82AF83E0FD5305FE8E828F83EDF0800D75820022CE",
	":200D6F0090E6B9E0F5820202EF7582012290E6B8E0FF6005BF026A801B90E6BAE0FFBF02C9",
	":200D8F0002806790E6BAE0FFBF0105751B01805A7582002290E6BAE0704390E6BCE0F582B7",
	":200DAF00120C4BAE82AF83EE4F7003F582228E828F83E0FD4305018E828F83EDF090E6BC97",
	":200DCF00E0FF53070F90E6BCE05480C423541FFE90E6832FF0E0FF74204FF0800D75820030",
	":200DEF002290E6B9E0F5820202EF75820122AF82D20210AF02C202EF600E751C1C751D1EEB",
	":200E0F00751E36751F1E800C751C36751D1E751E1C751F1EA20292AF2290E6BBE0FFBF010D",
	":200E2F00028019BF02028029BF03028033BF0603020EE3BF0703020EF8020F077E007F1E66",
	":200E4F008F0690E6B3EEF07E007F1E90E6B4EEF022AF1D90E6B3EFF0AE1C90E6B4EEF022DA",
	":200E6F007D507E1E7F8090E6BAE0F5227B008B020BEAB5220280428D008E018F028D828EF2",
	":200E8F00838FF0120F9F28F8E439F9880589068A0774012DF9E43EFA8F0489828A838CF0C0",
	":200EAF00120F9FF9B9030280067D007E007F00ED4E6006C3E5229B50B5ED4E600D8E0790D4",
	":200ECF00E6B3EFF090E6B4EDF02290E6A0E0FF74014FF0227E127F1E8F0690E6B3EEF07E50",
	":200EEF00127F1E90E6B4EEF022AF1F90E6B3EFF0AE1E90E6B4EEF02290E6A0E0FF74014F85",
	":020F0F00F022CE",
	":2001C6007900E94400601B7A00900FC0780075921CE493F2A308B800020592D9F4DAF27511",
	":0201E60092FF86",
	":010F110032AD",
	":010F120032AC",
	":010F130032AB",
	":1B0F140020F71130F6138883A88220F509F6A8837583002280FEF280F5F022DC",
	":010F2F00328F",
	":010F3000328E",
	":010F3100328D",
	":010F3200328C",
	":03004300021F0099",
	":201F0000020386000203AD000207D100020F11000203CE0002041D000207CE00020F3C006E",
	":201F2000020F3D00020F3E00020F3F00020F4200020F1300020F2F00020F3000020F320079",
	":201F4000020B2C00020F3C00020FBB000207CF000207D000020B2B00020B2D00020B2E00D1",
	":201F6000020F9E00020F3C00020F3C00020F3C00020F3B00020F4000020F4300020F450084",
	":201F8000020F4100020F4400020F4600020F9D00020F3300020F3500020F3700020F390079",
	":181FA000020F3400020F3600020F3800020F3A00020F3100020F1200A4",
	":010F3300328B",
	":010F3400328A",
	":2001EE007800E84400600A790075921CE4F309D8FC7800E84400600C7900901C00E4F0A3E7",
	":04020E00D8FCD9FA45",
	":010F35003289",
	":010F36003288",
	":010F37003287",
	":010F38003286",
	":010F39003285",
	":010F3A003284",
	":010F3B003283",
	":010F3C003282",
	":010F3D003281",
	":010F3E003280",
	":010F3F00327F",
	":010F4000327E",
	":010F4100327D",
	":010F4200327C",
	":010F4300327B",
	":010F4400327A",
	":010F45003279",
	":010F46003278",
	":200F4700AE82AF8390E600E05418C423541FFDB40100E433FD60067CB17D00801C90E60024",
	":200F6700E05418C423541FFBBB01067A617B0180047AC27B028A048B058C228D231522744C",
	":160F8700FFB522021523E522452370F11EBEFF011FEE4F70E422C6",
	":010F9D003221",
	":010F9E003220",
	":0D01B900758129120FBCE58260030201B6BA",
	":1C0F9F0020F71430F6148883A88220F507E6A88375830022E280F7E49322E02261",
	":010FBB003203",
	":040FBC007582002218",
	":00000001FF",
	NULL
};
