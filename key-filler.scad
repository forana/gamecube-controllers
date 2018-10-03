descenderDepth = 4.8;
descenderWidth = 14;
topWidth = 20;
topThickness = 2;

color("green")
    rotate([180, 0, 0])
        linear_extrude(0, 0, descenderDepth, scale = 0.9)
            square(descenderWidth, center = true);
color("cyan")
    linear_extrude(0, 0, topThickness)
        square(topWidth, center = true);
