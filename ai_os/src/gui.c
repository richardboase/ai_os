// src/gui.c
#include <gtk/gtk.h>
#include <stdlib.h>
#include <libgen.h>
#include <limits.h>
#include <string.h>
#include <mach-o/dyld.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *image;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "AI OS");

    // Set the default size of the window to 640x480
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

    // Determine the path to the executable
    char exe_path[PATH_MAX];
    uint32_t size = sizeof(exe_path);
    if (_NSGetExecutablePath(exe_path, &size) != 0) {
        g_printerr("Error: Unable to determine executable path\n");
        return;
    }

    // Get the directory of the executable
    char *dir = dirname(exe_path);

    // Construct the path to the GUI image
    char gui_path[PATH_MAX];
    snprintf(gui_path, sizeof(gui_path), "%s/GUI.png", dir);

    // Load the GUI image
    image = gtk_image_new_from_file(gui_path);
    if (!GTK_IS_WIDGET(image)) {
        g_printerr("Error: Unable to load GUI image from %s\n", gui_path);
        return;
    }

    // Scale the image to fit within the window
    gtk_image_set_pixel_size(GTK_IMAGE(image), 640);

    // Create a box to contain the image and set its properties
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
    gtk_container_add(GTK_CONTAINER(box), image);

    // Add the box to the window
    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);
}

int run_gui(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.GtkApplication", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}