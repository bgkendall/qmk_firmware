BEGIN {

    layer_name[ 0] = "KL_DEF";
    layer_name[ 1] = "KL_DEF1";
    layer_name[ 2] = "KL_DEF2";
    layer_name[ 3] = "KL_NUM";
    layer_name[ 4] = "KL_NP";
    layer_name[ 5] = "KL_FN";
    layer_name[ 6] = "KL_FN1";
    layer_name[ 7] = "KL_FN2";
    layer_name[ 8] = "KL_NAV";
    layer_name[ 9] = "KL_META";
    layer_name[10] = "KL_EXT1";
    layer_name[11] = "KL_EXT2";

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
