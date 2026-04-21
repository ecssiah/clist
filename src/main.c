#include "justsky/justsky.h"
#include "justsky/justsky_list.h"

typedef struct Vec3 Vec3;
struct Vec3
{
    f32 x;
    f32 y;
    f32 z;
};

#define vec3_init(x, y, z) ((Vec3){ (x), (y), (z) })

int main()
{
    f32 *float_list;
    list_init(float_list, 4);

    i32 *int_list;
    list_init(int_list, 8);

    Vec3 *vec3_list;
    list_init(vec3_list, 16);

    list_add(float_list, 0.0f);
    list_add(float_list, 1.0f);

    list_add(int_list, 5);
    list_add(int_list, 4);
    
    list_add(float_list, 2.0f);
    list_add(float_list, 3.0f);

    list_add(int_list, 3);
    list_add(int_list, 2);

    list_add(float_list, 4.0f);
    list_add(float_list, 5.0f);

    list_add(int_list, 1);
    list_add(int_list, 0);

    list_add(vec3_list, vec3_init(1.0f, 2.0f, 3.0f));
    list_add(vec3_list, vec3_init(2.0f, 4.0f, 6.0f));
    list_add(vec3_list, vec3_init(4.0f, 8.0f, 12.0f));

    f32 *float_item;
    list_for(float_list, float_item)
    {
        printf("%f\n", *float_item);
    }

    printf("Length: %zu\n", list_len(float_list));
    printf("Capacity: %zu\n", list_capacity(float_list));

    i32 *int_item;
    list_for(int_list, int_item)
    {
        printf("%i\n", *int_item);
    }

    printf("Length: %zu\n", list_len(int_list));
    printf("Capacity: %zu\n", list_capacity(int_list));

    list_clear(vec3_list);

    list_add(vec3_list, vec3_init(13.0f, 8.0f, 13.0f));
    
    Vec3 *vec3_item;
    list_for(vec3_list, vec3_item)
    {
        printf("%f %f %f\n", vec3_item->x, vec3_item->y, vec3_item->z);
    }

    printf("Length: %zu\n", list_len(int_list));
    printf("Capacity: %zu\n", list_capacity(int_list));
    
    return 0;
}
