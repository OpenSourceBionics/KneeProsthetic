<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.5.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="6" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="CC0402JRX7R7BB104">
<packages>
<package name="CAPC1005X55N">
<wire x1="0.53" y1="0.28" x2="-0.53" y2="0.28" width="0.127" layer="51"/>
<wire x1="-0.53" y1="0.28" x2="-0.53" y2="-0.28" width="0.127" layer="51"/>
<wire x1="-0.53" y1="-0.28" x2="0.53" y2="-0.28" width="0.127" layer="51"/>
<wire x1="0.53" y1="-0.28" x2="0.53" y2="0.28" width="0.127" layer="51"/>
<wire x1="0.5" y1="0.48" x2="-0.5" y2="0.48" width="0.127" layer="21"/>
<wire x1="-0.5" y1="-0.48" x2="0.5" y2="-0.48" width="0.127" layer="21"/>
<wire x1="0.85" y1="0.54" x2="-0.85" y2="0.54" width="0.05" layer="39"/>
<wire x1="-0.85" y1="0.54" x2="-0.85" y2="-0.54" width="0.05" layer="39"/>
<wire x1="-0.85" y1="-0.54" x2="0.85" y2="-0.54" width="0.05" layer="39"/>
<wire x1="0.85" y1="-0.54" x2="0.85" y2="0.54" width="0.05" layer="39"/>
<text x="-0.8034375" y="0.602578125" size="0.30610625" layer="25">&gt;NAME</text>
<text x="-0.803240625" y="-1.004059375" size="0.3060375" layer="27">&gt;VALUE</text>
<smd name="1" x="-0.43" y="0" dx="0.6" dy="0.54" layer="1" roundness="53" rot="R90"/>
<smd name="2" x="0.43" y="0" dx="0.6" dy="0.54" layer="1" roundness="53" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="CC0402JRX7R7BB104">
<text x="0" y="3.81" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="0" y1="-1.905" x2="0.635" y2="1.905" layer="94"/>
<rectangle x1="1.905" y1="-1.905" x2="2.54" y2="1.905" layer="94"/>
<pin name="1" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CC0402JRX7R7BB104" prefix="C">
<description>CAP CER 0.1UF 16V X7R 0402</description>
<gates>
<gate name="G$1" symbol="CC0402JRX7R7BB104" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC1005X55N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" Cap Ceramic 0.1uF 16V X7R 5% SMD 0402 125°C Paper T/R "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="311-1676-1-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.com/product-detail/en/yageo/CC0402JRX7R7BB104/311-1676-1-ND/5195578?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Yageo"/>
<attribute name="MP" value="CC0402JRX7R7BB104"/>
<attribute name="PACKAGE" value="0402 Yageo"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="RC0603JR-0710KL">
<packages>
<package name="RESC1607X60N">
<text x="-1.51" y="-0.85" size="0.5" layer="27" align="top-left">&gt;VALUE</text>
<text x="-1.51" y="0.85" size="0.5" layer="25">&gt;NAME</text>
<wire x1="0.9" y1="-0.51" x2="-0.9" y2="-0.51" width="0.127" layer="51"/>
<wire x1="0.9" y1="0.51" x2="-0.9" y2="0.51" width="0.127" layer="51"/>
<wire x1="0.9" y1="-0.51" x2="0.9" y2="0.51" width="0.127" layer="51"/>
<wire x1="-0.9" y1="-0.51" x2="-0.9" y2="0.51" width="0.127" layer="51"/>
<wire x1="-1.508" y1="-0.761" x2="1.508" y2="-0.761" width="0.05" layer="39"/>
<wire x1="-1.508" y1="0.761" x2="1.508" y2="0.761" width="0.05" layer="39"/>
<wire x1="-1.508" y1="-0.761" x2="-1.508" y2="0.761" width="0.05" layer="39"/>
<wire x1="1.508" y1="-0.761" x2="1.508" y2="0.761" width="0.05" layer="39"/>
<smd name="1" x="-0.735" y="0" dx="1.04" dy="1.02" layer="1"/>
<smd name="2" x="0.735" y="0" dx="1.04" dy="1.02" layer="1"/>
</package>
</packages>
<symbols>
<symbol name="RC0603JR-0710KL">
<wire x1="-2.54" y1="0" x2="-2.159" y2="1.016" width="0.2032" layer="94"/>
<wire x1="-2.159" y1="1.016" x2="-1.524" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="-1.524" y1="-1.016" x2="-0.889" y2="1.016" width="0.2032" layer="94"/>
<wire x1="-0.889" y1="1.016" x2="-0.254" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="-0.254" y1="-1.016" x2="0.381" y2="1.016" width="0.2032" layer="94"/>
<wire x1="0.381" y1="1.016" x2="1.016" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="1.016" y1="-1.016" x2="1.651" y2="1.016" width="0.2032" layer="94"/>
<wire x1="1.651" y1="1.016" x2="2.286" y2="-1.016" width="0.2032" layer="94"/>
<wire x1="2.286" y1="-1.016" x2="2.54" y2="0" width="0.2032" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="7.62" y="0" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="1" x="-7.62" y="0" visible="pad" length="middle" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="RC0603JR-0710KL" prefix="R">
<description>RC Series 0603 0.1 W 10 kOhms 5% ±100 ppm/°C SMT Thick Film Chip Resistor</description>
<gates>
<gate name="G$1" symbol="RC0603JR-0710KL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RESC1607X60N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" RC Series 0603 0.1 W 10 kOhms 5% ±100 ppm/°C SMT Thick Film Chip Resistor "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="311-10KGRCT-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.com/product-detail/en/yageo/RC0603JR-0710KL/311-10KGRCT-ND/729647?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Yageo"/>
<attribute name="MP" value="RC0603JR-0710KL"/>
<attribute name="PACKAGE" value="0603 Yageo"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="+5V" urn="urn:adsk.eagle:symbol:26929/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="+5V" urn="urn:adsk.eagle:component:26963/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="+5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="CC0603KRX7R7BB152">
<packages>
<package name="CAPC1608X90">
<description>&lt;b&gt;CAPACITOR&lt;/b&gt;</description>
<wire x1="-1.673" y1="0.783" x2="1.673" y2="0.783" width="0.0508" layer="39"/>
<wire x1="1.673" y1="0.783" x2="1.673" y2="-0.783" width="0.0508" layer="39"/>
<wire x1="1.673" y1="-0.783" x2="-1.673" y2="-0.783" width="0.0508" layer="39"/>
<wire x1="-1.673" y1="-0.783" x2="-1.673" y2="0.783" width="0.0508" layer="39"/>
<wire x1="-0.356" y1="0.432" x2="0.356" y2="0.432" width="0.1016" layer="51"/>
<wire x1="-0.356" y1="-0.419" x2="0.356" y2="-0.419" width="0.1016" layer="51"/>
<text x="-1.74096875" y="0.93821875" size="0.602065625" layer="25">&gt;NAME</text>
<text x="-1.737559375" y="-1.50723125" size="0.6008875" layer="27">&gt;VALUE</text>
<rectangle x1="-0.83860625" y1="-0.470128125" x2="-0.3381" y2="0.4801" layer="51"/>
<rectangle x1="0.33088125" y1="-0.47086875" x2="0.8303" y2="0.4801" layer="51"/>
<wire x1="-0.15" y1="0.45" x2="0.15" y2="0.45" width="0.127" layer="21"/>
<wire x1="-0.15" y1="-0.45" x2="0.15" y2="-0.45" width="0.127" layer="21"/>
<smd name="1" x="-0.85" y="0" dx="1.1" dy="1" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.1" dy="1" layer="1"/>
</package>
</packages>
<symbols>
<symbol name="CC0603KRX7R7BB152">
<text x="0" y="3.81" size="1.778" layer="95">&gt;NAME</text>
<text x="0" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="0" y1="-1.905" x2="0.635" y2="1.905" layer="94"/>
<rectangle x1="1.905" y1="-1.905" x2="2.54" y2="1.905" layer="94"/>
<pin name="1" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="2" x="-2.54" y="0" visible="pad" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CC0603KRX7R7BB152" prefix="C">
<description>0603 1.5 nF 16 V ±10 % Tolerance X7R SMT Multilayer Ceramic Capacitor</description>
<gates>
<gate name="G$1" symbol="CC0603KRX7R7BB152" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC1608X90">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" 0603 1.5 nF 16 V ±10 % Tolerance X7R SMT Multilayer Ceramic Capacitor "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="311-4064-1-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.com/product-detail/en/yageo/CC0603KRX7R7BB152/311-4064-1-ND/8025153?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Yageo"/>
<attribute name="MP" value="CC0603KRX7R7BB152"/>
<attribute name="PACKAGE" value="0603 Yageo"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="DRV5053PAQDBZR">
<packages>
<package name="SOT95P237X112-3N">
<text x="-2.54396875" y="2.54396875" size="1.017590625" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-2.5431" y="-3.81465" size="1.017240625" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
<wire x1="-0.7" y1="1.52" x2="0.7" y2="1.52" width="0.127" layer="51"/>
<wire x1="0.7" y1="1.52" x2="0.7" y2="-1.52" width="0.127" layer="51"/>
<wire x1="0.7" y1="-1.52" x2="-0.7" y2="-1.52" width="0.127" layer="51"/>
<wire x1="-0.7" y1="-1.52" x2="-0.7" y2="1.52" width="0.127" layer="51"/>
<wire x1="-0.7" y1="1.52" x2="0.7" y2="1.52" width="0.127" layer="21"/>
<wire x1="0.7" y1="1.52" x2="0.7" y2="0.5" width="0.127" layer="21"/>
<wire x1="0.7" y1="-0.5" x2="0.7" y2="-1.52" width="0.127" layer="21"/>
<wire x1="0.7" y1="-1.52" x2="-0.7" y2="-1.52" width="0.127" layer="21"/>
<circle x="-1.5" y="1.85" radius="0.15" width="0.2" layer="21"/>
<wire x1="-1.98" y1="1.8" x2="-1.98" y2="-1.8" width="0.05" layer="39"/>
<wire x1="-1.98" y1="-1.8" x2="1.98" y2="-1.8" width="0.05" layer="39"/>
<wire x1="1.98" y1="-1.8" x2="1.98" y2="1.8" width="0.05" layer="39"/>
<wire x1="1.98" y1="1.8" x2="-1.98" y2="1.8" width="0.05" layer="39"/>
<smd name="1" x="-1.055" y="0.95" dx="1.24" dy="0.59" layer="1" roundness="50"/>
<smd name="2" x="-1.055" y="-0.95" dx="1.24" dy="0.59" layer="1" roundness="50"/>
<smd name="3" x="1.0553" y="0" dx="1.24" dy="0.59" layer="1" roundness="50"/>
</package>
</packages>
<symbols>
<symbol name="DRV5053PAQDBZR">
<wire x1="-5.08" y1="7.62" x2="5.08" y2="7.62" width="0.41" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-7.62" width="0.41" layer="94"/>
<wire x1="5.08" y1="-7.62" x2="-5.08" y2="-7.62" width="0.41" layer="94"/>
<wire x1="-5.08" y1="-7.62" x2="-5.08" y2="7.62" width="0.41" layer="94"/>
<text x="-5.11593125" y="8.63963125" size="2.08755" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.12171875" y="-11.6472" size="2.087690625" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
<pin name="VCC" x="10.16" y="5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="OUT" x="10.16" y="0" length="middle" direction="out" rot="R180"/>
<pin name="GND" x="10.16" y="-5.08" length="middle" direction="pwr" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DRV5053PAQDBZR" prefix="U">
<description>SENSOR LINEAR ANALOG SOT23-3</description>
<gates>
<gate name="G$1" symbol="DRV5053PAQDBZR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT95P237X112-3N">
<connects>
<connect gate="G$1" pin="GND" pad="3"/>
<connect gate="G$1" pin="OUT" pad="2"/>
<connect gate="G$1" pin="VCC" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" 2.5 to 38 V Analog Bipolar Hall Effect Sensor 3-SOT-23 -40 to 125 "/>
<attribute name="DIGI-KEY_PART_NUMBER" value="296-38458-1-ND"/>
<attribute name="DIGI-KEY_PURCHASE_URL" value="https://www.digikey.com/product-detail/en/texas-instruments/DRV5053PAQDBZR/296-38458-1-ND/5022223?utm_source=snapeda&amp;utm_medium=aggregator&amp;utm_campaign=symbol"/>
<attribute name="MF" value="Texas Instruments"/>
<attribute name="MP" value="DRV5053PAQDBZR"/>
<attribute name="PACKAGE" value="SOT-23-3 Texas Instruments"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead" urn="urn:adsk.eagle:library:325">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X05" urn="urn:adsk.eagle:footprint:22354/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="1.905" y1="1.27" x2="3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.905" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-4.445" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="1.27" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-0.635" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-3.175" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="1.27" x2="-1.905" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-3.81" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="1.27" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-0.635" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="5.715" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="1.27" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="6.35" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-0.635" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="1.27" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-0.635" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="0" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="2.54" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="5.08" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-6.4262" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.35" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="2.286" y1="-0.254" x2="2.794" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="-2.794" y1="-0.254" x2="-2.286" y2="0.254" layer="51"/>
<rectangle x1="-5.334" y1="-0.254" x2="-4.826" y2="0.254" layer="51"/>
<rectangle x1="4.826" y1="-0.254" x2="5.334" y2="0.254" layer="51"/>
</package>
<package name="1X05/90" urn="urn:adsk.eagle:footprint:22355/1" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-6.35" y1="-1.905" x2="-3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="0.635" x2="-6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="0.635" x2="-6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="6.985" x2="-5.08" y2="1.27" width="0.762" layer="21"/>
<wire x1="-3.81" y1="-1.905" x2="-1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="6.985" x2="-2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="6.985" x2="0" y2="1.27" width="0.762" layer="21"/>
<wire x1="1.27" y1="-1.905" x2="3.81" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="0.635" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="6.985" x2="2.54" y2="1.27" width="0.762" layer="21"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="0.635" x2="3.81" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="6.985" x2="5.08" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="0" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="2.54" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="5.08" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-6.985" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="8.255" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-5.461" y1="0.635" x2="-4.699" y2="1.143" layer="21"/>
<rectangle x1="-2.921" y1="0.635" x2="-2.159" y2="1.143" layer="21"/>
<rectangle x1="-0.381" y1="0.635" x2="0.381" y2="1.143" layer="21"/>
<rectangle x1="2.159" y1="0.635" x2="2.921" y2="1.143" layer="21"/>
<rectangle x1="4.699" y1="0.635" x2="5.461" y2="1.143" layer="21"/>
<rectangle x1="-5.461" y1="-2.921" x2="-4.699" y2="-1.905" layer="21"/>
<rectangle x1="-2.921" y1="-2.921" x2="-2.159" y2="-1.905" layer="21"/>
<rectangle x1="-0.381" y1="-2.921" x2="0.381" y2="-1.905" layer="21"/>
<rectangle x1="2.159" y1="-2.921" x2="2.921" y2="-1.905" layer="21"/>
<rectangle x1="4.699" y1="-2.921" x2="5.461" y2="-1.905" layer="21"/>
</package>
<package name="1_05X2MM" urn="urn:adsk.eagle:footprint:22356/1" library_version="4">
<description>CON-M-1X5-200</description>
<text x="-4.5" y="1.5" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-4.75" y="-2.75" size="1.27" layer="27">&gt;VALUE</text>
<wire x1="-5" y1="0.5" x2="-4.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-4.5" y1="1" x2="-3.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-3.5" y1="1" x2="-3" y2="0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="-0.5" x2="-3.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-3.5" y1="-1" x2="-4.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-4.5" y1="-1" x2="-5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-5" y1="0.5" x2="-5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="0.5" x2="-2.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-2.5" y1="1" x2="-1.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-1.5" y1="1" x2="-1" y2="0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="-0.5" x2="-1.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-1.5" y1="-1" x2="-2.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-2.5" y1="-1" x2="-3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-3" y1="0.5" x2="-3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="0.5" x2="-0.5" y2="1" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="1" x2="0.5" y2="1" width="0.1524" layer="21"/>
<wire x1="0.5" y1="1" x2="1" y2="0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="-0.5" x2="0.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="0.5" y1="-1" x2="-0.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="-0.5" y1="-1" x2="-1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="-1" y1="0.5" x2="-1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="0.5" x2="1.5" y2="1" width="0.1524" layer="21"/>
<wire x1="1.5" y1="1" x2="2.5" y2="1" width="0.1524" layer="21"/>
<wire x1="2.5" y1="1" x2="3" y2="0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="-0.5" x2="2.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="2.5" y1="-1" x2="1.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="1.5" y1="-1" x2="1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="1" y1="0.5" x2="1" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="0.5" x2="3.5" y2="1" width="0.1524" layer="21"/>
<wire x1="3.5" y1="1" x2="4.5" y2="1" width="0.1524" layer="21"/>
<wire x1="4.5" y1="1" x2="5" y2="0.5" width="0.1524" layer="21"/>
<wire x1="5" y1="0.5" x2="5" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="5" y1="-0.5" x2="4.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="4.5" y1="-1" x2="3.5" y2="-1" width="0.1524" layer="21"/>
<wire x1="3.5" y1="-1" x2="3" y2="-0.5" width="0.1524" layer="21"/>
<wire x1="3" y1="0.5" x2="3" y2="-0.5" width="0.1524" layer="21"/>
<pad name="1" x="-4" y="0" drill="1.016" diameter="1.3" shape="square" rot="R90"/>
<pad name="3" x="0" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="2" x="-2" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="4" x="2" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<pad name="5" x="4" y="0" drill="1.016" diameter="1.3" rot="R90"/>
<rectangle x1="-4.254" y1="-0.254" x2="-3.746" y2="0.254" layer="51"/>
<rectangle x1="-2.254" y1="-0.254" x2="-1.746" y2="0.254" layer="51"/>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
<rectangle x1="1.746" y1="-0.254" x2="2.254" y2="0.254" layer="51"/>
<rectangle x1="3.746" y1="-0.254" x2="4.254" y2="0.254" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="1X05" urn="urn:adsk.eagle:package:22469/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X05"/>
</packageinstances>
</package3d>
<package3d name="1X05/90" urn="urn:adsk.eagle:package:22467/2" type="model" library_version="4">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X05/90"/>
</packageinstances>
</package3d>
<package3d name="1_05X2MM" urn="urn:adsk.eagle:package:22466/2" type="model" library_version="4">
<description>CON-M-1X5-200</description>
<packageinstances>
<packageinstance name="1_05X2MM"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PINHD5" urn="urn:adsk.eagle:symbol:22353/1" library_version="4">
<wire x1="-6.35" y1="-7.62" x2="1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="7.62" x2="-6.35" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="7.62" x2="-6.35" y2="-7.62" width="0.4064" layer="94"/>
<text x="-6.35" y="8.255" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X5" urn="urn:adsk.eagle:component:22529/5" prefix="JP" uservalue="yes" library_version="4">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD5" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X05">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22469/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="69" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X05/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22467/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="9" constant="no"/>
</technology>
</technologies>
</device>
<device name="5X2MM" package="1_05X2MM">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22466/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="C1" library="CC0402JRX7R7BB104" deviceset="CC0402JRX7R7BB104" device=""/>
<part name="C2" library="CC0402JRX7R7BB104" deviceset="CC0402JRX7R7BB104" device=""/>
<part name="C3" library="CC0402JRX7R7BB104" deviceset="CC0402JRX7R7BB104" device=""/>
<part name="R1" library="RC0603JR-0710KL" deviceset="RC0603JR-0710KL" device=""/>
<part name="R2" library="RC0603JR-0710KL" deviceset="RC0603JR-0710KL" device=""/>
<part name="R3" library="RC0603JR-0710KL" deviceset="RC0603JR-0710KL" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="C4" library="CC0603KRX7R7BB152" deviceset="CC0603KRX7R7BB152" device=""/>
<part name="U1" library="DRV5053PAQDBZR" deviceset="DRV5053PAQDBZR" device=""/>
<part name="U2" library="DRV5053PAQDBZR" deviceset="DRV5053PAQDBZR" device=""/>
<part name="U3" library="DRV5053PAQDBZR" deviceset="DRV5053PAQDBZR" device=""/>
<part name="JP1" library="pinhead" library_urn="urn:adsk.eagle:library:325" deviceset="PINHD-1X5" device="5X2MM" package3d_urn="urn:adsk.eagle:package:22466/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="C1" gate="G$1" x="50.8" y="38.1" smashed="yes">
<attribute name="NAME" x="50.8" y="41.91" size="1.778" layer="95"/>
<attribute name="VALUE" x="50.8" y="33.02" size="1.778" layer="96"/>
</instance>
<instance part="C2" gate="G$1" x="50.8" y="68.58" smashed="yes">
<attribute name="NAME" x="50.8" y="72.39" size="1.778" layer="95"/>
<attribute name="VALUE" x="50.8" y="63.5" size="1.778" layer="96"/>
</instance>
<instance part="C3" gate="G$1" x="50.8" y="99.06" smashed="yes">
<attribute name="NAME" x="50.8" y="102.87" size="1.778" layer="95"/>
<attribute name="VALUE" x="50.8" y="93.98" size="1.778" layer="96"/>
</instance>
<instance part="R1" gate="G$1" x="30.48" y="38.1" smashed="yes">
<attribute name="NAME" x="26.67" y="39.5986" size="1.778" layer="95"/>
<attribute name="VALUE" x="26.67" y="34.798" size="1.778" layer="96"/>
</instance>
<instance part="R2" gate="G$1" x="30.48" y="68.58" smashed="yes">
<attribute name="NAME" x="26.67" y="70.0786" size="1.778" layer="95"/>
<attribute name="VALUE" x="26.67" y="65.278" size="1.778" layer="96"/>
</instance>
<instance part="R3" gate="G$1" x="30.48" y="99.06" smashed="yes">
<attribute name="NAME" x="26.67" y="100.5586" size="1.778" layer="95"/>
<attribute name="VALUE" x="26.67" y="95.758" size="1.778" layer="96"/>
</instance>
<instance part="P+1" gate="1" x="81.28" y="121.92" smashed="yes">
<attribute name="VALUE" x="78.74" y="116.84" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="GND1" gate="1" x="78.74" y="5.08" smashed="yes">
<attribute name="VALUE" x="76.2" y="2.54" size="1.778" layer="96"/>
</instance>
<instance part="C4" gate="G$1" x="88.9" y="25.4" smashed="yes" rot="R90">
<attribute name="NAME" x="85.09" y="25.4" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="93.98" y="25.4" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="U1" gate="G$1" x="7.62" y="99.06" smashed="yes">
<attribute name="NAME" x="2.50406875" y="107.69963125" size="2.08755" layer="95" ratio="10" rot="SR0"/>
<attribute name="VALUE" x="2.49828125" y="87.4128" size="2.087690625" layer="96" ratio="10" rot="SR0"/>
</instance>
<instance part="U2" gate="G$1" x="7.62" y="68.58" smashed="yes">
<attribute name="NAME" x="2.50406875" y="77.21963125" size="2.08755" layer="95" ratio="10" rot="SR0"/>
<attribute name="VALUE" x="2.49828125" y="56.9328" size="2.087690625" layer="96" ratio="10" rot="SR0"/>
</instance>
<instance part="U3" gate="G$1" x="7.62" y="38.1" smashed="yes">
<attribute name="NAME" x="2.50406875" y="46.73963125" size="2.08755" layer="95" ratio="10" rot="SR0"/>
<attribute name="VALUE" x="2.49828125" y="26.4528" size="2.087690625" layer="96" ratio="10" rot="SR0"/>
</instance>
<instance part="JP1" gate="A" x="-27.94" y="68.58" smashed="yes" rot="R180">
<attribute name="NAME" x="-21.59" y="60.325" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="-21.59" y="78.74" size="1.778" layer="96" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U3" gate="G$1" pin="OUT"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="22.86" y1="38.1" x2="17.78" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U2" gate="G$1" pin="OUT"/>
<pinref part="R2" gate="G$1" pin="1"/>
<wire x1="22.86" y1="68.58" x2="17.78" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="OUT"/>
<pinref part="R3" gate="G$1" pin="1"/>
<wire x1="22.86" y1="99.06" x2="17.78" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="C1" gate="G$1" pin="2"/>
<wire x1="48.26" y1="38.1" x2="43.18" y2="38.1" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="43.18" y1="38.1" x2="38.1" y2="38.1" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="63.5" x2="-7.62" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="63.5" x2="-7.62" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="20.32" x2="43.18" y2="20.32" width="0.1524" layer="91"/>
<wire x1="43.18" y1="20.32" x2="43.18" y2="38.1" width="0.1524" layer="91"/>
<junction x="43.18" y="38.1"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="2"/>
<pinref part="C2" gate="G$1" pin="2"/>
<wire x1="48.26" y1="68.58" x2="43.18" y2="68.58" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="43.18" y1="68.58" x2="38.1" y2="68.58" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="66.04" x2="-2.54" y2="66.04" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="66.04" x2="-2.54" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="53.34" x2="43.18" y2="53.34" width="0.1524" layer="91"/>
<wire x1="43.18" y1="53.34" x2="43.18" y2="68.58" width="0.1524" layer="91"/>
<junction x="43.18" y="68.58"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="2"/>
<pinref part="C3" gate="G$1" pin="2"/>
<wire x1="48.26" y1="99.06" x2="43.18" y2="99.06" width="0.1524" layer="91"/>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="43.18" y1="99.06" x2="38.1" y2="99.06" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="68.58" x2="-2.54" y2="68.58" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="68.58" x2="-2.54" y2="83.82" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="83.82" x2="43.18" y2="83.82" width="0.1524" layer="91"/>
<wire x1="43.18" y1="83.82" x2="43.18" y2="99.06" width="0.1524" layer="91"/>
<junction x="43.18" y="99.06"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="P+1" gate="1" pin="+5V"/>
<pinref part="C4" gate="G$1" pin="1"/>
<wire x1="88.9" y1="30.48" x2="81.28" y2="43.18" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="VCC"/>
<wire x1="81.28" y1="43.18" x2="81.28" y2="73.66" width="0.1524" layer="91"/>
<wire x1="81.28" y1="73.66" x2="81.28" y2="104.14" width="0.1524" layer="91"/>
<wire x1="81.28" y1="104.14" x2="81.28" y2="114.3" width="0.1524" layer="91"/>
<wire x1="81.28" y1="114.3" x2="81.28" y2="119.38" width="0.1524" layer="91"/>
<wire x1="17.78" y1="73.66" x2="81.28" y2="73.66" width="0.1524" layer="91"/>
<junction x="81.28" y="73.66"/>
<pinref part="U1" gate="G$1" pin="VCC"/>
<wire x1="17.78" y1="104.14" x2="81.28" y2="104.14" width="0.1524" layer="91"/>
<junction x="81.28" y="104.14"/>
<pinref part="U3" gate="G$1" pin="VCC"/>
<wire x1="17.78" y1="43.18" x2="81.28" y2="43.18" width="0.1524" layer="91"/>
<junction x="81.28" y="43.18"/>
<junction x="81.28" y="114.3"/>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="-17.78" y1="114.3" x2="81.28" y2="114.3" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="73.66" x2="-17.78" y2="73.66" width="0.1524" layer="91"/>
<wire x1="-17.78" y1="73.66" x2="-17.78" y2="114.3" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="C1" gate="G$1" pin="1"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="55.88" y1="38.1" x2="60.96" y2="38.1" width="0.1524" layer="91"/>
<wire x1="60.96" y1="38.1" x2="66.04" y2="38.1" width="0.1524" layer="91"/>
<wire x1="66.04" y1="38.1" x2="73.66" y2="38.1" width="0.1524" layer="91"/>
<wire x1="73.66" y1="38.1" x2="78.74" y2="38.1" width="0.1524" layer="91"/>
<wire x1="78.74" y1="38.1" x2="78.74" y2="15.24" width="0.1524" layer="91"/>
<pinref part="C4" gate="G$1" pin="2"/>
<wire x1="78.74" y1="15.24" x2="78.74" y2="12.7" width="0.1524" layer="91"/>
<wire x1="78.74" y1="12.7" x2="78.74" y2="7.62" width="0.1524" layer="91"/>
<wire x1="88.9" y1="22.86" x2="81.28" y2="15.24" width="0.1524" layer="91"/>
<wire x1="81.28" y1="15.24" x2="78.74" y2="15.24" width="0.1524" layer="91"/>
<junction x="78.74" y="15.24"/>
<pinref part="C2" gate="G$1" pin="1"/>
<wire x1="55.88" y1="68.58" x2="66.04" y2="68.58" width="0.1524" layer="91"/>
<wire x1="66.04" y1="68.58" x2="66.04" y2="63.5" width="0.1524" layer="91"/>
<junction x="66.04" y="38.1"/>
<pinref part="C3" gate="G$1" pin="1"/>
<wire x1="66.04" y1="63.5" x2="66.04" y2="38.1" width="0.1524" layer="91"/>
<wire x1="55.88" y1="99.06" x2="73.66" y2="99.06" width="0.1524" layer="91"/>
<wire x1="73.66" y1="99.06" x2="73.66" y2="93.98" width="0.1524" layer="91"/>
<junction x="73.66" y="38.1"/>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="73.66" y1="93.98" x2="73.66" y2="38.1" width="0.1524" layer="91"/>
<wire x1="17.78" y1="93.98" x2="73.66" y2="93.98" width="0.1524" layer="91"/>
<junction x="73.66" y="93.98"/>
<pinref part="U2" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="63.5" x2="66.04" y2="63.5" width="0.1524" layer="91"/>
<junction x="66.04" y="63.5"/>
<pinref part="U3" gate="G$1" pin="GND"/>
<wire x1="17.78" y1="33.02" x2="60.96" y2="33.02" width="0.1524" layer="91"/>
<wire x1="60.96" y1="33.02" x2="60.96" y2="38.1" width="0.1524" layer="91"/>
<junction x="60.96" y="38.1"/>
<junction x="78.74" y="12.7"/>
<pinref part="JP1" gate="A" pin="4"/>
<wire x1="-33.02" y1="12.7" x2="78.74" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-25.4" y1="71.12" x2="-33.02" y2="71.12" width="0.1524" layer="91"/>
<wire x1="-33.02" y1="71.12" x2="-33.02" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
