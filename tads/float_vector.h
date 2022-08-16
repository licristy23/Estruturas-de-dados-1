typedef struct float_vector FloatVector;

FloatVector *creat(int tam);
void destroy(FloatVector **ref_vector);
int size(const FloatVector *vector);
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int pos);
float get(const FloatVector *vector, int endereco);
void append(FloatVector *vector, float n);
void print(const FloatVector *vector);