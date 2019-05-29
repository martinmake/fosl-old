{
using namespace Cabs::Positions;
using namespace Cabs::Colors;

widget1.position({LEFT, TOP});
widget1.size({21, 20});
widget1.label("WIDGET 1");
widget1.is_bordered(true);
widget1.is_shadowed(true);
widget1.is_visible (true);

histogram.position({CENTER, TOP});
histogram.size({51, 10});
histogram.label("HISTOGRAM");
histogram.is_bordered(true);
histogram.is_shadowed(true);
histogram.is_visible (true);

// You are unable to see this widget's is_bordered,
// is_shadowed and label but it still has
// dedicated space to draw it's contents on
widget3.position({RIGHT, TOP});
widget3.size({21, 20});
widget3.label("");
widget3.is_bordered(false);
widget3.is_shadowed(false);
widget3.is_visible (true);

widget4.position({LEFT, CENTER});
widget4.size({31, 10});
widget4.label("WIDGET 4");
widget4.is_bordered(true);
widget4.is_shadowed(true);
widget4.is_visible (true);

text_box.position({CENTER, CENTER});
text_box.size({31, 20});
text_box.label("TEXT BOX");
text_box.is_bordered(true);
text_box.is_shadowed(true);
text_box.is_visible (true);
text_box.padding({1, 2, 1, 2});
text_box.text(
		"   <!BLUE_BLACK>THIS IS SAMPLE TEXT\n"
		"       SAMPLE TEXT\n"
		"           TEXT<!GREEN_BLACK>\n"
		"   TEXT\n"
		"    TEXT\n"
		"     TEXT\n"
		"      TEXT\n"
		"       TEXT\n"
		"        TEEEEEEEEEEE0123456789XT\n"
		"         TEXT\n"
		"            TEXT\n"
		"               TEXT\n"
		"                  TEXT\n"
		"             TEXT\n"
		"            TEXT\n"
		"           TEXT"
	     );

widget6.position({RIGHT, CENTER});
widget6.size({31, 10});
widget6.label("WIDGET 6");
widget6.is_bordered(true);
widget6.is_shadowed(true);
widget6.is_visible (true);

widget7.position({LEFT, BOTTOM});
widget7.size({21, 20});
widget7.label("WIDGET 7");
widget7.is_bordered(false);
widget7.is_shadowed(false);
widget7.is_visible (true);

graph.position({CENTER, BOTTOM});
graph.size({51, 10});
graph.label("GRAPH");
graph.is_bordered(true);
graph.is_shadowed(true);
graph.is_visible (true);

widget9.position({RIGHT, BOTTOM});
widget9.size({21, 20});
widget9.label("WIDGET 9");
widget9.is_bordered(true);
widget9.is_shadowed(true);
widget9.is_visible (true);

*this << widget1;
*this << histogram;
*this << widget3;
*this << widget4;
*this << text_box;
*this << widget6;
*this << widget7;
*this << graph;
*this << widget9;
}
