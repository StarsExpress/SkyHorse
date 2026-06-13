import React from 'react';
import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
import styles from '../css/about.module.css';
import {useLocation} from '@docusaurus/router';

const socials = [
  {
      label: 'GitHub',
      href: 'https://github.com/StarsExpress',
      icon: (
          <svg viewBox="0 0 24 24" width="18" height="18" fill="currentColor">
              <path d="M12 0C5.37 0 0 5.37 0 12c0 5.31 3.435 9.795 8.205 11.385.6.105.825-.255.825-.57 0-.285-.015-1.23-.015-2.235-3.015.555-3.795-.735-4.035-1.41-.135-.345-.72-1.41-1.23-1.695-.42-.225-1.02-.78-.015-.795.945-.015 1.62.87 1.845 1.23 1.08 1.815 2.805 1.305 3.495.99.105-.78.42-1.305.765-1.605-2.67-.3-5.46-1.335-5.46-5.925 0-1.305.465-2.385 1.23-3.225-.12-.3-.54-1.53.12-3.18 0 0 1.005-.315 3.3 1.23.96-.27 1.98-.405 3-.405s2.04.135 3 .405c2.295-1.56 3.3-1.23 3.3-1.23.66 1.65.24 2.88.12 3.18.765.84 1.23 1.905 1.23 3.225 0 4.605-2.805 5.625-5.475 5.925.435.375.81 1.095.81 2.22 0 1.605-.015 2.895-.015 3.3 0 .315.225.69.825.57A12.02 12.02 0 0 0 24 12c0-6.63-5.37-12-12-12z"/>
          </svg>
      )
  },
  {
      label: 'LinkedIn',
      href: 'https://www.linkedin.com/in/yuan-jack-yao/',
      icon: (
          <svg viewBox="0 0 24 24" width="18" height="18" fill="#0A66C2">
              <path d="M20.447 20.452h-3.554v-5.569c0-1.328-.027-3.037-1.852-3.037-1.853 0-2.136 1.445-2.136 2.939v5.667H9.351V9h3.414v1.561h.046c.477-.9 1.637-1.85 3.37-1.85 3.601 0 4.267 2.37 4.267 5.455v6.286zM5.337 7.433a2.062 2.062 0 0 1-2.063-2.065 2.064 2.064 0 1 1 2.063 2.065zm1.782 13.019H3.555V9h3.564v11.452zM22.225 0H1.771C.792 0 0 .774 0 1.729v20.542C0 23.227.792 24 1.771 24h20.451C23.2 24 24 23.227 24 22.271V1.729C24 .774 23.2 0 22.222 0h.003z"/>
          </svg>
      )
  },
];

export default function About() {
  const location = useLocation();
  const isChinese = location.pathname.includes('/zh-Hans/') || location.pathname.endsWith('/zh-Hans');

  return (
    <Layout title="About Me" description="Personal Profile">
      <main style={{
        maxWidth: 1500,
        margin: '4rem auto',
        padding: '0 1.5rem',
        display: 'flex',
        flexDirection: 'column',
        alignItems: 'center',
      }}>

        {/* Top: avatar + intro. Placed at center. */}
        <div style={{
          display: 'flex',
          gap: '3rem',
          alignItems: 'flex-start',
          flexWrap: 'wrap',
          justifyContent: 'center',
          maxWidth: 700,
          width: '100%',
        }}>

          {/* Left: photo. */}
          <div style={{flexShrink: 0, textAlign: 'center'}}>
            <img
              src="/SkyHorse/img/my_photo.jpg"
              alt="Avatar"
              style={{
                width: 180,
                height: 180,
                borderRadius: '50%',
                objectFit: 'cover',
                border: '3px solid var(--ifm-color-primary)',
              }}
            />
          </div>

          {/* Right: intro + social media. */}
          <div style={{flex: 1, minWidth: 260}}>

            {/* Title. */}
            <h1 className={isChinese ? styles.zhiMangXing : styles.caveat} style={{marginBottom: '0.5rem'}}>
                {isChinese ? '东流' : 'Mr.Faraway'}
            </h1>

            {/* Intro. */}
            <p className={isChinese ? styles.zhiMangXing : styles.caveat} style={{marginBottom: '1.5rem'}}>
                {isChinese ? '莫听穿林打叶声 不随流水即随风' : 'Add sparkles to your sky.'}
            </p>

            {/* Social media: standard. */}
            <div style={{display: 'flex', gap: '0.75rem', flexWrap: 'wrap', marginTop: '1.5rem'}}>
              {socials.map(s => (
                <Link
                  key={s.label}
                  href={s.href}
                  className={styles.standard}
                  style={{
                    display: 'flex',
                    alignItems: 'center',
                    gap: '0.4rem',
                    padding: '0.4rem 1rem',
                    borderRadius: 8,
                    border: '1px solid var(--ifm-color-emphasis-300)',
                    textDecoration: 'none',
                    fontWeight: 500,
                  }}>
                  {s.icon} {s.label}
                </Link>
              ))}
            </div>
          </div>

        </div>

        {/* Bottom: photo + description side by side w/ full length. */}
        <div style={{
          display: 'flex',
          gap: '2rem',
          alignItems: 'center',
          marginTop: '2.5rem',
          flexWrap: 'wrap',
          width: '100%',
        }}>
          <img
            src="/SkyHorse/img/submissions_history.png"
            alt="4699 Submissions In 2024"
            style={{
              flex: '1 1 400px',
              maxWidth: '65%',
              borderRadius: 12,
              border: '1px solid var(--ifm-color-emphasis-200)',
            }}
          />

          {/* Words for submissions history. */}
          <div className={isChinese ? styles.maShanZheng : styles.playfairDisplay} style={{
            flex: '1 1 260px',
            lineHeight: 2,
          }}>
            <p style={{margin: 0}}>{isChinese ? '仔细想想 平时显得爱玩不太认真' : 'At times I look quite unserious and playful'}</p>
            <p style={{margin: 0}}>{isChinese ? '可能是闭门练功后 自然的能量平衡吧' : 'Is likely just some rebalanced energy after hard work'}</p>
            <p style={{margin: 0}}>{isChinese ? '回首过往 连自己也没想到会专心' : 'Looking back, I never know that one day'}</p>
            <p style={{margin: 0}}>{isChinese ? '不停沉思要怎么节省代码行数' : 'I would devote a lot of time into trimming code'}</p>
            <p style={{margin: 0}}>{isChinese ? '同时升级可读性 大幅提速 花更少空间' : 'Enhancing readability and speed, while saving space'}</p>
            <p style={{margin: 0}}>{isChinese ? '多少朝夕默默地沉浸于程序中' : 'To all these days quietly dedicated to coding'}</p>
          </div>
        </div>

      </main>
    </Layout>
  );
}
