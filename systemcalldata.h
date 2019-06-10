struct sysCallData{
  int id;
  int pid;
  int hour;
  int minute;
  int day;
  int month;
  int year;
};
struct sysCallData m_calls[100];
int increase_data(struct sysCallData data);
int count;
int counts[23];
int index;
int list_size;
char* data_types[23];
char* names[23];
