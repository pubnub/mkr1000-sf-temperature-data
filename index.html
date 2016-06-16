<!--DOCTYPE html-->

<html>
    <head>
        <meta charset="utf-8">
        <meta name='viewport' content='initial-scale=1,maximum-scale=1,user-scalable=no' />
        <link rel="stylesheet" href="main.css">
        <script type="text/javascript" src="http://pubnub.github.io/eon/v/eon/0.0.10/eon.js"></script>
        <link type="text/css" rel="stylesheet" href="http://pubnub.github.io/eon/v/eon/0.0.10/eon.css"/>  
        <script src='https://api.mapbox.com/mapbox.js/v2.4.0/mapbox.js'></script>
        <link href='https://api.mapbox.com/mapbox.js/v2.4.0/mapbox.css' rel='stylesheet' />
    </head>
    
    
    <body>
        <div id="title">
            <header id="h1">SUBCLIMATES OF SAN FRANCISCO</header>
            <header id="h2">Realtime Temperature and Humidity Data</header>
        </div>
        <div id="buttons">
            <button type="button" id="chartview" onclick="hideshow('map','charts')">Chart View</button>
            <button type="button" id="mapview" onclick="hideshow('charts','map')">Map View</button>
        </div>
        <div id="charts">
            <div id="chart1"></div>
            <div id="chart2"></div>
        </div>
        <div id="map"></div>
    </body>


<script type="text/javascript">
    map1 = document.getElementById('map');
    map1.style.display = 'none';
    var __eon_pubnub = PUBNUB.init({
      subscribe_key: "sub-c-cb3facb2-f234-11e5-8b0b-0619f8945a4f"
    });
    var __eon_cols = ["SoMa","Richmond","Mission"]; 
    var __eon_labels = {}; 
    __eon_pubnub.history({
        channel: "temperature",
        count: 1,
        callback: function(m) {
        }
    });
    
    
    L.mapbox.accessToken = 'pk.eyJ1IjoiZW1tYXJvc2VtdyIsImEiOiJjaXBnMDZrcWgwMDBtdG9ua2RyeHUwZzB0In0.jbn2Kwtz7DP4pKcNiVuyrQ';
    var map = L.mapbox.map('map', 'mapbox.streets')
    .setView([37.7749, -122.4194], 13);
    
    L.mapbox.featureLayer({
    // this feature is in the GeoJSON format: see geojson.org
    // for the full specification
    type: 'Feature',
    geometry: {
        type: 'Point',
        // coordinates here are in longitude, latitude order because
        // x, y is the standard for GeoJSON and many formats
        coordinates: [-122.505798,37.776956]
    },
    properties: {
        title: 'Outer Richmond',
        description: '',
        // one can customize markers by adding simplestyle properties
        // https://www.mapbox.com/guides/an-open-platform/#simplestyle
        'marker-size': 'large',
        'marker-color': '#f86767',
    }
}).addTo(map);
    
    function hideshow(hideid, showid) {
        var hide=document.getElementById(hideid);
        var show=document.getElementById(showid)
        hide.style.display = 'none';
        show.style.display = 'block';
        map.invalidateSize()
    };

    chart1 = eon.chart({
      pubnub: __eon_pubnub,
      channel: "temperature",
      history: true,
      flow: true,
      rate: 1000,
      limit: 20,
      generate: {
        bindto: "#chart1",
        data: {
          colors: {"SoMa":"#D70060","Richmond":"#113F8C", "Mission":"#01A4A4"},
          type: "spline"
        },
        transition: {
          duration: 250
        },
        axis: {
          x: {
            label: "Time"
          },
          y: {
            label: "Temperature (°F)"
          }
        },
        grid: {
          x: {
            show: false 
          },
          y: {
            show: false 
          }
        },
        tooltip: {
         show: true
        },
        point: {
          show: true
        }
      },
      transform: function(message) {
        var message = eon.c.flatten(message.eon);
        var o = {};
        for(index in message) {
          if(__eon_cols.indexOf(index) > -1){
            o[__eon_labels[index] || index] = message[index];
          }
        }
        return {
          eon: o
        };
      }
    });

    chart2 = eon.chart({
      pubnub: __eon_pubnub,
      channel: "humidity",
      history: true,
      flow: true,
      rate: 1000,
      limit: 20,
      generate: {
        bindto: "#chart2",
        data: {
          colors: {"SoMa":"#D70060","Richmond":"#113F8C","Mission":"#01A4A4"},
          type: "spline"
        },
        transition: {
          duration: 250
        },
        axis: {
          x: {
            label: "Time"
          },
          y: {
            label: "Humidity (%)"
          }
        },
        grid: {
          x: {
            show: false 
          },
          y: {
            show: false 
          }
        },
        tooltip: {
         show: true
        },
        point: {
          show: true
        }
      },
      transform: function(message) {
        var message = eon.c.flatten(message.eon);
        var o = {};
        for(index in message) {
          if(__eon_cols.indexOf(index) > -1){
            o[__eon_labels[index] || index] = message[index];
          }
        }
        return {
          eon: o
        };
      }
    });
    
    
</script>
</html>
