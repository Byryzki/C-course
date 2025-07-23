#ifndef KUUKAUDET
#define KUUKAUDET

enum kuukaudet
{
    TAMMIKUU = 0,
    HELMIKUU,
    MAALISKUU,
    HUHTIKUU,
    TOUKOKUU,
    KESAKUU,
    HEINAKUU,
    ELOKUU,
    SYYSKUU,
    LOKAKUU,
    MARRASKUU,
    JOULUKUU
};

enum maara {KK_LKM = 12};

static const char *KK_NIMET[KK_LKM];
static const char KK_PAIVAT[2][KK_LKM];

int karkausvuosi(int y);
char kkPituus(const char *monthName, int y);

#endif