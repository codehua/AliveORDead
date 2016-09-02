#ifndef _APP_CONSTANT_H_
#define _APP_CONSTANT_H_

#include "cocos2d.h"
USING_NS_CC;
#include "SimpleAudioEngine.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include "platform/android/jni/Java_org_cocos2dx_lib_Cocos2dxHelper.h"
#include <jni.h>
#endif

//stand c++ library
#include <vector>
#include <string>

static const int LEVEL_NUM = 45;//关卡数量

//正常老鼠
static const char* ACTION_badger_normal[] = {
	"badger_normal0.png",
	"badger_normal1.png",
	"badger_normal2.png",
};

//敏捷老鼠
static const char* ACTION_badger_deft[] = {
	"badger_deft0.png",
	"badger_deft1.png",
	"badger_deft2.png",
};

//强壮老鼠
static const char* ACTION_badger_strong[] = {
	"badger_strong0.png",
	"badger_strong1.png",
	"badger_strong2.png",
};

//换衣老鼠
static const char* ACTION_badger_change[] = {
	"badger_color0.png",
	"badger_color2.png",
	"badger_color1.png",
};


//换衣老鼠
static const char* ACTION_badger_change_1[] = {
	"badger_color3.png",
	"badger_color8.png",
	"badger_color4.png",
};


//蓝色老鼠
static const char* ACTION_badger_bule[] = {
	"badger_color6.png",
	"badger_color2.png",
	"badger_color4.png",
};

//黄色老鼠
static const char* ACTION_badger_yellow[] = {
	"badger_color3.png",
	"badger_color7.png",
	"badger_color1.png",
};

//橙色老鼠
static const char* ACTION_badger_orange[] = {
	"badger_color0.png",
	"badger_color8.png",
	"badger_color5.png",
};

//炸弹图片
static const char * ACTION_boom[] = {
	"boomb.png",
};

//大便图片
static const char * ACTION_shit[] = {
	"shit.png",
};

//恶魔图片
static const char * ACTION_evil[] = {
	"evil.png",
};

//炸弹特效
static const char* ACTION_Effect_boomb[] = {
	"boomb_1.png",
	"boomb_2.png",
	"boomb_3.png",
	"boomb_4.png",
	"boomb_5.png",
};

//衣服
static const char* IMG_clothes[] = {
	"clothes_1.png",
	"clothes_2.png",
	"clothes_3.png",
	"clothes_4.png",
	"clothes_5.png",
	"clothes_6.png",
	"clothes_7.png",
	"clothes_8.png",
};

//脸
static const char* ACTION_face[] = {
	"face0.png",
	"face1.png",
};

//冰特效
static const char* ACTION_bing[] = {
	"bing0.png",
	"bing1.png",
	"bing2.png",
};

//火特效
static const char* ACTION_fire[] = {
	"fire_1.png",
	"fire_2.png",
	"fire_3.png",
	"fire_4.png",
};

//主界面的老鼠王
static const char* ACTION_Main_king[] = {
	"king3.png",
	"king4.png",
};

//老鼠王
static const char* ACTION_king[] = {
	"king0.png",
	"king1.png",
	"king2.png",
	"king3.png",
	"king4.png",
	"king5.png",
	"king6.png",
};

//蜘蛛
static const char* ACTION_spider[] = {
	"spider_1.png",
	"spider_2.png",
	"spider_3.png",
	"spider_4.png",
	"spider_5.png",
};

//铲土
static const char* ACTION_spray[] = {
	"spray_1.png",
	"spray_2.png",
	"spray_3.png",
};

//敲击到动画
static const char* ACTION_mace[] = {
	"mace0.png",
	"mace1.png",
	"mace2.png",
	"mace3.png",
};

//倒计时
static const char * ACTION_daojishi[] = {
	"three.png",
	"two.png",
	"one.png",
	"startgame.png",
};

//洞穴类型
static const int DONGXUE_TYPE[6][3][3]= {
	0, 1, 0, 1, 1, 1, 0, 1, 0,
	1, 0, 1, 0, 1, 0, 1, 0, 1,
	1, 1, 1, 0, 1, 0, 1, 1, 1,
	1, 0, 1, 1, 1, 1, 1, 0, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1,
};

//道具类型
enum DAOJU_TYPE
{
	DAOJU_TYPE_NAOZHONG = 1,//闹钟
	DAOJU_TYPE_ZHADAN,		//炸弹
	DAOJU_TYPE_HUOQIU,		//火球
	DAOJU_TYPE_TIECHAN, 	//铁铲
	DAOJU_TYPE_MOFABANG,	//魔法棒

	GIFT_TYPE_MIESHU,		//灭鼠大礼包
	GIFT_TYPE_GANEN,		//感恩大礼包
	GIFT_TYPE_MAOXUE,		//满血复活
	GIFT_OPEN_ALL_LEVEL,	//开启所有关卡
	GIFT_OPEN_LEVEL,		//开启当前关卡
};

//地鼠类型 
enum H_TYPE
{
	H_TYPE_NORMAL = 1,  //普通老鼠
	H_TYPE_DEFT,	    //敏捷老鼠
	H_TYPE_STRONG,		//强壮老鼠
	H_TYPE_CHANGE,		//换衣老鼠
	H_TYPE_CHANGE_1,	//换衣老鼠2
	H_TYPE_BULE,		//蓝色老鼠
	H_TYPE_YELLOW,		//黄色老鼠
	H_TYPE_ORANGE,		//橙色老鼠
	H_TYPE_SHIT,		//大便
	H_TYPE_BOOMB,		//炸弹
	H_TYPE_EVIL,		//恶魔
};

//地鼠状态
enum H_STAYUS
{
	H_NORMAL = 1,  //正常状态
	H_DEATH,	   //死亡状态
	H_APP,		   //正在出现
	H_REAL_DEATH,  //真正死亡状态
	H_SAFETY,	   //带安全帽状态
	H_DISAPP	   //正在消失状态
};

//地鼠动画
enum H_ACTION
{
	H_ACTION_CHANGE = 1,//切换表情动画
	H_ACTION_SHAKE,		//抖动动画
	H_ACTION_APP,		//出现动画
	H_ACTION_DISAPP,	//消失动画
};


//------ 音效 ----------
static char * AUDIO_PASS	= "audio_pass.mp3";		//
static char * BADGER_HIT_0	= "badger_hit0.mp3";	//打击音效
static char * BADGER_HIT_1	= "badger_hit1.mp3";	//打击音效
static char * BADGER_HIT_2	= "badger_hit2.mp3";	//打击音效
static char * BADGER_OUT	= "badger_out.mp3";		//老鼠出现音效
static char * BOSS_BOOM		= "boss_boom.mp3";		//boss爆炸音效
static char * BOSS_HIT		= "boss_hit.mp3";		//打击boss音效
static char * G_DJ_BOMB		= "g_dj_bomb.mp3";		//炸弹道具音效
static char * G_DJ_FIRE		= "g_dj_fire.mp3";		//火道具音效
static char * G_DJ_ICE		= "g_dj_ice.mp3";		//冰块道具音效	
static char * G_DJ_NAOZHONG = "g_dj_naozhong.mp3";	//闹钟道具音效
static char * G_DJ_TIECHAN	= "g_dj_tiechan.mp3";	//铁铲道具音效
static char * GAME_FAIL		= "game_fail.mp3";		//游戏失败音效
static char * GAME_MUSIC	= "game_music.mp3";		//游戏音乐
static char * GAME_WIN		= "game_win.mp3";		//游戏成功音效
static char * HIT_BALK		= "hit_balk.mp3";		//
static char * BTN_CLICK		= "btnclick.mp3";		//按钮点击音效


//------道具ID----------
static const int ID_ZS_500=1;
//--------END-----------------
static void showPayJNI(int payId)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, "com/untory/run/clear1/PayTool", "pay", "(I)V"))
	{
		t.env->CallStaticVoidMethod(t.classID, t.methodID, payId);
		t.env->DeleteLocalRef(t.classID);
	}
#endif
}

#endif
