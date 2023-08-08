BEGIN {
    NUMBER_OF_LAYERS = 6;

    layer_name[0] = "KL_DEF";
    layer_name[1] = "KL_NUM";
    layer_name[2] = "KL_NP";
    layer_name[3] = "KL_FN";
    layer_name[4] = "KL_FN1";
    layer_name[5] = "KL_META";

    for (l = 0; l < NUMBER_OF_LAYERS; l++)
    {
        layer_init[l] = layer_name[l];
        layer_omit[l] = 0;
    }

    layer_init[3] = "KL_FN...KL_FN1";
    layer_omit[4] = 1;
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
