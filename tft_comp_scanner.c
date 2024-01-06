#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NBEST 15

enum traits{
	ADMIN=1<<0,
	AnimaSquad=1<<1,
	Arsenal=1<<2,
	Civilian=1<<3,
	Gadgeteen=1<<4,
	LaserCorps=1<<5,
	MechaPRIME=1<<6,
	OxForce=1<<7,
	StarGuardian=1<<8,
	Supers=1<<9,
	Threat=1<<10,
	Underground=1<<11,
	Ace=1<<12,
	Aegis=1<<13,
	Brawler=1<<14,
	Corrupted=1<<15,
	Defender=1<<16,
	Duelist=1<<17,
	Forecaster=1<<18,
	Hacker=1<<19,
	Heart=1<<20,
	Mascot=1<<21,
	Prankster=1<<22,
	Recon=1<<23,
	Renegade=1<<24,
	Spellslinger=1<<25,
	Sureshot=1<<26
};

const struct{
	const char* name;
	uint16_t tiers[4];
	double values[4];
}traitInfo[]={
	{"ADMIN",{2,4,6,99},{2.0,4.0,5.8}},
    {"AnimaSquad",{3,5,7,99},{2.0,3.0,4.0}},
    {"Arsenal",{1,99,99,99},{0.0}},
    {"Civilian",{1,2,3,99},{0.4,1.5,6.0}},
    {"Gadgeteen",{3,5,99,99},{3.5,4.0}},
    {"LaserCorps",{3,6,9,99},{8.0,12.0,7.0}},
    {"MechaPRIME",{3,5,99,99},{2.2,5.0}},
    {"OxForce",{2,4,6,8},{1.5,2.0,2.7,3.8}},
    {"StarGuardian",{3,5,7,9},{6.5,7.0,9.0,8.5}},
    {"Supers",{3,99,99,99},{2.0,2.0,1,0}},//unit bonus
    {"Threat",{1,99,99,99},{0.0}},
    {"Underground",{3,5,99,99},{6.5,8.0}},
    {"Ace",{1,4,99,99},{1.0,6.0}},
    {"Aegis",{2,3,4,5},{2.1,3.5,4.0,6.0}},
    {"Brawler",{2,4,6,8},{2.1,4.0,5.5,7.0}},
    {"Corrupted",{1,99,99,99},{0.0}},
    {"Defender",{2,4,6,99},{2.1,6.0,10.0}},
    {"Duelist",{2,4,6,8},{1.5,6.5,6.0,7.0}},
    {"Forecaster",{1,99,99,99},{0.0}},
    {"Hacker",{2,3,4,99},{2.5,2.9,4.0}},
    {"Heart",{2,4,6,99},{1.5,5.5,8.0}},
    {"Mascot",{2,4,6,8},{2.1,4.7,10.0,99.0}},
    {"Prankster",{2,3,99,99},{2.5,4.0}},
    {"Recon",{2,3,4,99},{2.0,2.5,3.0,8.0}},
    {"Renegade",{3,6,99,99},{6.5,8.0}},
    {"Spellslinger",{2,4,6,8},{1.75,5.5,8.0,10.0}},
    {"Sureshot",{2,4,99,99},{2.5,8.0}},
};

const struct{
	const char* name;
	uint32_t cost;
	uint32_t traits;

}pool[]={
	{"Alistar",3,OxForce|Aegis|Mascot},
	{"Annie",2,Gadgeteen|OxForce|Spellslinger},
	{"Aphelios",5,Arsenal|OxForce|Sureshot},
	{"Ashe",1,LaserCorps|Recon},
	{"Aurelion Sol",4,Threat},
	{"BelVeth",4,Threat},
	{"Blitzcrank",1,ADMIN|Brawler},
	{"Camille",2,ADMIN|Renegade},
	{"Cho'Gath",3,Threat},
	{"Draven",2,MechaPRIME|Ace},
	{"Ekko",4,StarGuardian|Aegis|Prankster},
	{"Ezreal",2,Underground|Recon},
	{"Fiddlesticks",5,Threat|Corrupted},
	{"Fiora",2,OxForce|Duelist},
	{"Galio",1,Civilian|Mascot},
	{"Gangplank",1,Supers|Duelist},
	{"Janna",5,Civilian|Forecaster|Spellslinger},
	{"Jax",3,MechaPRIME|Brawler},
	{"Jinx",2,AnimaSquad|Prankster},
	{"Kai'Sa",3,StarGuardian|Recon},
	{"Kayle",1,Underground|Duelist},
	{"LeBlanc",3,ADMIN|Hacker|Spellslinger},
	{"Lee Sin",2,Supers|Brawler|Heart},
	{"Leona",5,MechaPRIME|Aegis|Renegade},
	{"Lulu",1,Gadgeteen|Heart},
	{"Lux",1,StarGuardian|Spellslinger},
	{"Malphite",2,Supers|Mascot},
	{"Miss Fortune",4,AnimaSquad|Ace},
	{"Mordekaiser",5,LaserCorps|Ace},
	{"Nasus",1,AnimaSquad|Mascot},
	{"Nilah",3,StarGuardian|Duelist},
	{"Nunu",5,Gadgeteen|Mascot},
	{"Poppy",1,Gadgeteen|Defender},
	{"Rammus",3,Threat},
	{"Rell",2,StarGuardian|Defender},
	{"Renekton",1,LaserCorps|Brawler},
	{"Riven",3,AnimaSquad|Brawler|Defender},
	{"Samira",4,Underground|Ace|Sureshot},
	{"Sejuani",4,LaserCorps|Brawler},
	{"Senna",3,LaserCorps|Sureshot},
	{"Sett",4,MechaPRIME|Defender},
	{"Sivir",2,Civilian|Sureshot},
	{"Sona",3,Underground|Heart|Spellslinger},
	{"Soraka",4,ADMIN|Heart},
	{"Sylas",1,AnimaSquad|Renegade},
	{"Syndra",5,StarGuardian|Heart},
	{"Taliyah",4,StarGuardian|Spellslinger},
	{"Talon",1,OxForce|Renegade},
	{"Urgot",5,Threat},
	{"Vayne",3,AnimaSquad|Duelist|Recon},
	{"Velkoz",3,Threat},
	{"Vi",2,Underground|Aegis|Brawler},
	{"Viego",4,OxForce|Renegade},
	{"Wukong",1,MechaPRIME|Defender},
	{"Yasuo",2,MechaPRIME|Defender},
	{"Yuumi",2,StarGuardian|Heart|Mascot},
	{"Zac",4,Threat},
	{"Zed",4,LaserCorps|Duelist|Hacker},
	{"Zoe",3,Gadgeteen|Hacker|Prankster},
};

size_t findChamp(const char*const restrict name){//match first 3 characters
	size_t i=0;
	while(
		(name[0]&0x1F)!=(pool[i].name[0]&0x1F)||
		(name[1]&0x1F)!=(pool[i].name[1]&0x1F)||
		(name[2]&0x1F)!=(pool[i].name[2]&0x1F)
	){i++;}
	return i+((name[0]&0x1F)=='T'&&(name[3]&0x1F)=='O');//haha yuck
}

double score(const uint64_t inv,char print){
	double out=0.0;
	for(size_t i=0;i<27;i++){
		size_t n=0;
		uint64_t invT=inv;
		while(invT){
			size_t a=__builtin_ctzll(invT);
			invT&=~(1ull<<a);
			n+=(pool[a].traits>>i)&1ull;
		}
		
		size_t j=0;
		for(;j<4;j++){
			if(n>=traitInfo[i].tiers[j]){
				if((1<<i)==Supers){
					for(size_t k=0;k<64;k++){
						if((inv>>k)&1ull && pool[k].cost<4){
							out+=traitInfo[i].values[pool[k].cost];
						}
					}
				}else{
					out+=traitInfo[i].values[j];
				}
			}else{break;}
		}
		if(print&&j){printf("%s(%llu), ",traitInfo[i].name,j);}
	}
	return out;
}

//sifts bits right in a way that eventually covers all configurations
uint64_t sift(uint64_t inv){
	size_t a;
	if(a=__builtin_ctzll(inv)){return (inv&~(1ull<<a))|(1ull<<(a-1));}
	
	uint64_t packed=0;
	size_t i=0;
	do{
		packed|=(1ull<<i);
		inv&=~packed;
		i++;
		if(!inv){return 0;}
	}while((inv>>i)&1ull);
	
	a=__builtin_ctzll(inv);
	return
		(inv&~(1ull<<a))|//shift right most bit...
		(1ull<<(a-1))|//to the right once...
		(packed<<(a-i-1));//and add the right-packed ones back in
}

char isValid(uint64_t inv){//check for early high cost champs
	size_t level=__builtin_popcountll(inv);
	while(inv){
		size_t a=__builtin_ctzll(inv);
		inv&=~(1ull<<a);
		if(
			(pool[a].cost==5&&level<8)||
			(pool[a].cost==4&&level<7)||
			(pool[a].cost==3&&level<5)
		){return 0;}
	}
	return 1;
}

int main(){
	uint64_t inv=0;

	size_t nAdd;{
		char buff[50];
		printf("Input Champ Name(Or Number of Additional Champs to Consider to Start): ");
		scanf("%s",buff);
		while(buff[0]<'0' || buff[0]>'9'){
			inv|=1ull<<findChamp(buff);
			printf("Input Champ Name(Or Number of Additional Champs to Consider to Start): ");
			scanf("%s",buff);
		}
		nAdd=buff[0]-'0';
	}
	
	for(size_t i=2;i<nAdd;i++){
		struct{uint64_t inv;double score;}best[NBEST+1]={};
		
		uint64_t j=0;
		for(size_t k=0;k<=i;k++){
			j>>=1;
			j|=1ull<<58;
		};
		while(j){
			double curr=score(inv|j,0);
			for(size_t k=NBEST;k;k--){
				if(curr>=best[k-1].score){
					best[k]=best[k-1];
					best[k-1].inv=inv|j;
					best[k-1].score=curr;
				}
			}
			while(!isValid(j=sift(j))){}
		}
		printf("\n\n(%llu)\n",__builtin_popcountll(best[j].inv));
		for(size_t j=0;j<NBEST;j++){
			printf("%f:\n(",best[j].score);
			score(best[j].inv,1);
			printf(")\n(");
			while(best[j].inv){
				size_t a=__builtin_ctzll(best[j].inv);
				best[j].inv&=~(1ull<<a);
				printf("%s, ",pool[a].name);
			}
			printf(")\n\n");
		}
	}
}