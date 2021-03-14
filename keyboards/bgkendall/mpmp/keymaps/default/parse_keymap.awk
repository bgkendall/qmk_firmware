BEGIN {
    layer_name[0] = "KL_NUM";
    layer_name[1] = "KL_CALC";
    layer_name[2] = "KL_APP";
    layer_name[3] = "KL_FN";
    layer_name[4] = "KL_LED";

    NUMBER_OF_LAYERS = 0;
    for (l in layer_name) NUMBER_OF_LAYERS++;

    for (l = 0; l < NUMBER_OF_LAYERS; l++)
    {
        layer_init[l] = layer_name[l];
        layer_omit[l] = 0;
    }
}

{
    for (l = 0; l < NUMBER_OF_LAYERS; l++)
    {
        if (layer_omit[l] == 1)
        {
            sub("\\[" l "\\].*", "// Layer " layer_name[l] " not defined separately");
        }
        else
        {
            gsub("\\[" l "\\]", "[" layer_init[l] "]");
        }

        gsub("\\(" l "\\)", "(" layer_name[l] ")");
        gsub("\\(" l ",",   "(" layer_name[l] ",");
    }

    print;
}
