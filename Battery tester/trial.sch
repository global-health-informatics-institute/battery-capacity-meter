<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.1.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
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
<library name="Current  senosor">
<packages>
<package name="ACS714E">
<wire x1="-10.707" y1="11.889" x2="9.903" y2="11.889" width="0.127" layer="51"/>
<wire x1="9.903" y1="11.889" x2="9.903" y2="-6.913" width="0.127" layer="51"/>
<wire x1="9.903" y1="-6.913" x2="-10.707" y2="-6.913" width="0.127" layer="51"/>
<wire x1="-10.707" y1="-6.913" x2="-10.707" y2="11.889" width="0.127" layer="51"/>
<pad name="6" x="-6.353" y="7.73" drill="3.556" diameter="6"/>
<pad name="7" x="-6.353" y="-2.37" drill="3.556" diameter="6"/>
<text x="-0.177" y="-2.501" size="2.54" layer="25" font="vector">GHII</text>
<text x="-6.863" y="2.44" size="0.6096" layer="25" font="vector">Global Health Informatics Institute</text>
<circle x="-6.329" y="7.723" radius="3.60555" width="0.127" layer="21"/>
<circle x="-6.329" y="-2.377" radius="3.60555" width="0.127" layer="21"/>
<pad name="1" x="8.397" y="7.728" drill="1" diameter="1.5" shape="square"/>
<pad name="2" x="8.397" y="5.174" drill="1" diameter="1.5" shape="square"/>
<pad name="3" x="8.414" y="2.631" drill="1" diameter="1.5" rot="R90"/>
<pad name="4" x="8.346" y="0.08" drill="1" diameter="1.5"/>
<pad name="5" x="8.34" y="-2.46" drill="1" diameter="1.5"/>
</package>
</packages>
<symbols>
<symbol name="ACS715">
<wire x1="-9.144" y1="8.128" x2="11.176" y2="8.128" width="0.254" layer="94"/>
<wire x1="11.176" y1="8.128" x2="11.176" y2="-9.652" width="0.254" layer="94"/>
<wire x1="11.176" y1="-9.652" x2="-9.144" y2="-9.652" width="0.254" layer="94"/>
<wire x1="-9.144" y1="-9.652" x2="-9.144" y2="8.128" width="0.254" layer="94"/>
<pin name="P$1" x="16.256" y="5.588" length="middle" rot="R180"/>
<pin name="GND" x="16.256" y="3.048" length="middle" rot="R180"/>
<pin name="VCC" x="16.256" y="0.508" length="middle" rot="R180"/>
<pin name="OUT" x="16.256" y="-2.032" length="middle" rot="R180"/>
<pin name="FAULT" x="16.256" y="-4.572" length="middle" rot="R180"/>
<pin name="P$6" x="-14.224" y="3.048" length="middle"/>
<pin name="P$7" x="-14.224" y="-4.572" length="middle"/>
<text x="-10.16" y="10.16" size="1.778" layer="95">ACS7 14</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ACS714E">
<gates>
<gate name="G$1" symbol="ACS715" x="0" y="0"/>
</gates>
<devices>
<device name="GHII-ACS714" package="ACS714E">
<connects>
<connect gate="G$1" pin="FAULT" pad="5"/>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="OUT" pad="4"/>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="VCC" pad="3"/>
</connects>
<technologies>
<technology name=""/>
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
<part name="U$1" library="Current  senosor" deviceset="ACS714E" device="GHII-ACS714"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="43.18" y="53.34"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
