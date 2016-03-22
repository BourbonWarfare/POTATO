img = gimp.Image(2048, 2048, RGB)
layer = gimp.Layer(img, "Test", 2048, 2048, RGBA_IMAGE, 100, NORMAL_MODE)
img.add_layer(layer, -1)
pdb.gimp_image_set_active_layer(img, layer)
draw = pdb.gimp_image_get_active_drawable(img)
pdb.gimp_context_set_brush_size(4.0)

pdb.gimp_pencil(draw, 4, [1024-155,0.05*2048, 1024+155,0.05*2048])
pdb.gimp_pencil(draw, 4, [1024+155,0.05*2048, 1024+155,0.95*2048])
pdb.gimp_pencil(draw, 4, [1024+155,0.95*2048, 1024-155,0.95*2048])
pdb.gimp_pencil(draw, 4, [1024-155,0.95*2048, 1024-155,0.05*2048])


pdb.gimp_pencil(draw, 4, [1024,0,1024,2048])

pdb.gimp_pencil(draw, 4, [1024-54, 1024, 1024+54, 1024])

y = 2048 - 204.8 - 1638.4 * 1.0085
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.949375
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.888925
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.8265
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.761925
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.69375
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.620325
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.54075
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.44915
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.338925
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.26725
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.2255
pdb.gimp_pencil(draw, 4, [41+1024, y, 122+1024, y])
y = 2048 - 204.8 - 1638.4 * 0.17075
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])
y = 2048 - 204.8 - 1638.4 * 0
pdb.gimp_pencil(draw, 4, [1024, y, 163+1024, y])


y = 2048 - 204.8 - 60 - 1638.4 * 1.0085
pdb.gimp_text (img, draw, 30+1024, y, "200", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0.8265
pdb.gimp_text (img, draw, 30+1024, y, "500", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0.620325
pdb.gimp_text (img, draw, 30+1024, y, "800", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0.44915
pdb.gimp_text (img, draw, 17+1024, y, "1000", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0.26725
pdb.gimp_text (img, draw, 17+1024, y, "1150", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0.17075
pdb.gimp_text (img, draw, 17+1024, y, "1200", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )
y = 2048 - 204.8 - 60 - 1638.4 * 0
pdb.gimp_text (img, draw, 17+1024, y, "1235", 0, TRUE, 50, 0, "*", "*", "*", "*", "*", "*", "*", "*" )


disp1 = gimp.Display(img)
