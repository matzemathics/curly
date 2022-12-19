#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <jansson.h>

int main(void)
{
    FILE *tmp_file = tmpfile();

    CURL *curl = curl_easy_init();

    if (!curl)
    {
        fprintf(stderr, "Error initializing curl\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://xkcd.com/info.0.json");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmp_file);
    CURLcode res = curl_easy_perform(curl);

    rewind(tmp_file);

    json_t *json = json_loadf(tmp_file, 0, NULL);
    if (!json)
    {
        fprintf(stderr, "Cannot parse json response\n");
        return 1;
    }

    const char *title = json_string_value(json_object_get(json, "safe_title"));
    const char *day = json_string_value(json_object_get(json, "day"));
    const char *month = json_string_value(json_object_get(json, "month"));
    const char *year = json_string_value(json_object_get(json, "year"));

    printf("Current xkcd is titled '%s' (%s/%s/%s)\n", title, year, month, day);

    const char *image_link = json_string_value(json_object_get(json, "img"));

    char *image_name = malloc(strlen(year) + strlen(month) + strlen(day) + strlen(title) + 10);
    sprintf(image_name, "%s-%s-%s--%s.png", year, month, day, title);

    printf("saving as %s\n", image_name);
    FILE *image_file = fopen(image_name, "wb");

    // query the image
    curl_easy_reset(curl);
    curl_easy_setopt(curl, CURLOPT_URL, image_link);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, image_file);
    res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    fclose(tmp_file);
    fclose(image_file);

    return 0;
}
