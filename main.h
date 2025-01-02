typedef struct stlifestyle stlifestyle;
struct stlifestyle
{
    int id[10000];
    int physical_activity[10000];
    float alcohol_consumption[10000];
    float caffeine_consumption[10000];
    float sleep_quality[10000];
};

typedef struct stpatients stpatients;
struct stpatients {
    int patient_id[10000];
    int record_id[10000];
    int age[10000];
    char gender[10000];
    float weight[10000];
    int height[10000];
    int systolic_bp[10000];
    int diastolic_bp[10000];
    float heart_rate[10000];
    int condition[10000]; 
};
