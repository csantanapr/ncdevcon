import { Component } from '@angular/core';
import { DomSanitizationService } from '@angular/platform-browser';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  templateUrl: 'build/pages/detail/detail.html',
})
export class DetailPage {
  selectedVideo: any;

  constructor(private navCtrl: NavController, navParams: NavParams, private sanitizer: DomSanitizationService) {
    let video = navParams.get('video');
    this.selectedVideo = video.snippet;
    this.selectedVideo.playUrl=`https://www.youtube.com/watch?v=${video.id.videoId}`;
    this.selectedVideo.embedUrl=`https://www.youtube.com/embed/${video.id.videoId}?autoplay=1`;  
    this.selectedVideo.sanitizeUrl=this.sanitizer.bypassSecurityTrustResourceUrl(this.selectedVideo.embedUrl);
    //console.log(this.selectedVideo);
   }
}
