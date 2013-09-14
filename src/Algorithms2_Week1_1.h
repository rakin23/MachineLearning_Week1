
typedef struct
{
   int diff;
   int weight;
   int length;
   bool scheduled;
} PROJECT_STRUCT;

void ReadFile(const char * inName, PROJECT_STRUCT * data);
int ScheduleMaxDifferenceJob(PROJECT_STRUCT * data, int size);
